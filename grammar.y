%{
#include <stdio.h>
#include <errno.h>
#include "symbol.h"
extern double dpow();
extern double dfact();
extern void push();
%}

%union { double val; symbol *sym; }

%token <val> NUMBER
%token <sym> VAR BLTIN UNDEF
%type <val> expr asgn
%left '<' '>' LTE GTE NEQ
%right '='
%left '+' '-'
%left '*' '/'
%left '%'
%left UNARYPLUS
%left UNARYMINUS
%right '^'
%left '!'

%%

statement: 
| statement asgn ';'
| statement expr ';' { 
  symbol *s; s = lookup("p"); 
  if (!s) 
    execerr("cannot find p", NULL);
  s->u.val = $2; printf("  %.8g\n", $2);
  push($2);
}
;

asgn: VAR '=' expr { 
  if ( isreadonly($1->name) ) 
    execerr("readonly variable", $1->name);
  $$ = $1->u.val = $3; $1->type = VAR;
  }
;

expr: NUMBER
| VAR { 
  if ($1->type == UNDEF) 
    execerr("undefined variable", $1->name);
  $$ = $1->u.val;
}
| asgn
| BLTIN '(' expr ')' { $$ = (*($1->u.ptr))($3); }
| BLTIN '(' ')' { $$ = (*($1->u.ptr))(); }
| expr '+' expr { $$ = $1 + $3; }
| expr '-' expr { $$ = $1 - $3; }
| expr '*' expr { $$ = $1 * $3; }
| expr '/' expr { 
  if ($3 == 0.0) 
    execerr("division by zero", NULL);
  $$ = $1 / $3; }
| expr '%' expr { $$ = (int) $1 % (int) $3; }
| expr '^' expr { $$ = dpow($1, $3); }
| '(' expr ')'  { $$ = $2; }
| '+' expr %prec UNARYPLUS { $$ = $2; }
| '-' expr %prec UNARYMINUS { $$ = -$2; }
| expr '!' { $$ = dfact($1); }
| expr '<' expr { $$ = $1 < $3 ? 1 : 0; }
| expr '>' expr { $$ = $1 > $3 ? 1 : 0; }
| expr LTE expr { $$ = $1 <= $3 ? 1 : 0; }
| expr GTE expr { $$ = $1 >= $3 ? 1 : 0; }
| expr NEQ expr { $$ = $1 != $3 ? 1 : 0; }
;
%%

#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

char *progname; int lineno = 1; jmp_buf begin;

int yylex(void); 
void warn(char *, char *); 
void yyerror(char *s); 
int yyparse(); 
void fpecatch(int); 
void execerr(char *, char *);
void init(void); 
int isreadonly(char*);

int main(int argc, char *argv[])
{
  progname = argv[0]; 
  init();
  setjmp(begin); 
  signal(SIGFPE, fpecatch);
  yyparse(); 
  exit(0);
}

int yylex(void)
{
  int c;
  while ( (c = getchar()) == ' ' || c == '\t' || c == '\n') {
    if (c == '\n') ++lineno; 
    continue;
  }

  if (c == EOF) return 0;

  if (c == '.' || isdigit(c)) { 
    ungetc(c, stdin); 
    scanf("%lf", &yylval.val); 
    return NUMBER;
  }

  if (c == '=') {
    int x; x = getchar(); if (x == '\\') return NEQ;
    
    /* then it's assignment, so throw x back */
    ungetc(x, stdin); return c;
  }

  if (c == '<') {
    int x; x = getchar(); if (x == '=') return LTE;

    /* then it's <, so throw x back */
    ungetc(x, stdin); return c;
  }

  if (c == '>') {
    int x; x = getchar(); if (x == '=') return GTE;

    /* then it's >, so throw x back */
    ungetc(x, stdin); return c;
  }

  if (isalpha(c)) {
    symbol *s; char sbf[SYMSIZE + 1]; char *p; p = sbf;

    do { *p++ = c; } /* eat symbol while is doesn't exceed SYMSIZE */
    while( (c=getchar()) != EOF && isalnum(c) && (p - sbf < (SYMSIZE + 1)) );

    if ( (p - sbf) == SYMSIZE + 1) { /* too long */
      warn("token too long", (char*) 0); 
      longjmp(begin, 0);
    }

    ungetc(c, stdin); *p = '\0'; /* throw back the last char */
    if ( (s=lookup(sbf)) == 0 ) 
      s = install(sbf, UNDEF, 0.0);
    
    yylval.sym = s; 
    return s->type == UNDEF ? VAR : s->type;
  }

  return c; /* matches everything else */
}

void warn(char *s, char *t)
{
  fprintf(stderr, "%s: %s", progname, s); 
  if (t) fprintf(stderr, " %s", t);
  fprintf(stderr, " near line %d\n", lineno);
}

void yyerror(char *s)
{
  warn(s, NULL);
}

void execerr(char *s, char *t)
{
  warn(s, t); longjmp(begin, 0);
}

void fpecatch(int e)
{
  execerr("floating point exception", NULL);
}
