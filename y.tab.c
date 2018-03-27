#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20050813

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "grammar.y"
#include <errno.h>
#include "symbol.h"
extern double dpow();
extern double dfact();
#line 8 "grammar.y"
typedef union { double val; symbol *sym; } YYSTYPE;
#line 29 "y.tab.c"
#define NUMBER 257
#define VAR 258
#define BLTIN 259
#define UNDEF 260
#define LTE 261
#define GTE 262
#define NEQ 263
#define UNARYPLUS 264
#define UNARYMINUS 265
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
short yylen[] = {                                         2,
    0,    3,    3,    3,    1,    1,    1,    4,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    3,
    3,    3,    3,    3,
};
short yydefred[] = {                                      1,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,    3,    2,    0,
    9,    0,   16,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    8,
};
short yydgoto[] = {                                       1,
    8,   13,
};
short yysindex[] = {                                      0,
  -25,    0,  -60,  -35,  -25,  -25,  -25,  -26,  -46,  -25,
   14,  -30,    0,  -30,   -2,  -25,  -25,  -25,  -25,  -25,
  -25,  -25,  -25,  -25,  -25,  -25,    0,    0,    0,  175,
    0,    5,    0,  175,  175,  175,  175,  175,  164,  164,
  -31,  -31,  -30,  -30,    0,
};
short yyrindex[] = {                                      0,
    0,    0,  -33,    0,    0,    0,    0,    0,   29,    0,
    0,   36,    0,   43,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  123,
    0,    0,    0,  128,  132,  136,  140,  145,  108,  116,
   96,  103,   67,   74,    0,
};
short yygindex[] = {                                      0,
  404,   21,
};
#define YYTABLESIZE 430
short yytable[] = {                                       6,
   10,   27,   27,    6,   11,   25,   27,    6,    6,    6,
   25,    6,   29,    6,    7,   23,   21,    5,   22,    6,
   24,    9,    0,    0,    0,    6,    6,    0,    6,    0,
   27,    0,   28,   16,   25,   17,    0,   27,   33,   23,
   21,   25,   22,    0,   24,   45,   23,   21,    0,   22,
    0,   24,    0,    7,   31,    0,    5,   16,    6,   17,
    6,    7,   26,   26,   16,    7,   17,   26,    0,    0,
    7,    7,   17,    7,    0,    7,   17,   17,   17,   18,
   17,    0,   17,   18,   18,   18,    0,   18,    7,   18,
    7,   26,    0,    0,   17,   17,    0,   17,   26,    0,
    0,   18,   18,   14,   18,    0,    0,   14,   14,   14,
   15,   14,    0,   14,   15,   15,   15,    0,   15,    0,
   15,    0,    7,    0,    0,   14,   14,    0,   14,    0,
    0,    0,   15,   15,    0,   15,   12,   12,   12,    0,
   12,    0,   12,   13,   13,   13,    0,   13,   10,   13,
   10,    0,   10,    0,   12,   12,   11,   12,   11,    0,
   11,   13,   13,    4,   13,    0,   10,   10,   20,   10,
    0,    0,   21,    0,   11,   11,   22,   11,    0,    0,
   23,    4,    4,    0,    4,   24,   20,   20,    0,   20,
   21,   21,    0,   21,   22,   22,   27,   22,   23,   23,
   25,   23,    0,   24,   24,   23,   24,   27,    0,    0,
   24,   25,    0,    0,    0,    0,   23,   21,    0,   22,
    0,   24,    0,    0,    0,    0,    0,    6,    6,    6,
    0,    2,    3,    4,   18,   19,   20,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,   18,   19,
   20,    0,    0,    0,    0,   18,   19,   20,   26,    0,
    2,    3,    4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    7,    7,    0,    0,    0,    0,   17,   17,   17,    0,
    0,    0,    0,   18,   18,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   14,   14,   14,
    0,    0,    0,    0,   15,   15,   15,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   12,   12,   12,    0,
    0,    0,    0,   13,   13,   13,    0,    0,   10,   10,
   10,    0,    0,    0,    0,    0,   11,   11,   11,    0,
    0,    0,    0,    4,    4,    4,    0,    0,   20,   20,
   20,    0,   21,   21,   21,    0,   22,   22,   22,    0,
   23,   23,   23,    0,    0,   24,   24,   24,   12,   14,
   15,    0,    0,   30,   32,    0,    0,    0,    0,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,
};
short yycheck[] = {                                      33,
   61,   33,   33,   37,   40,   37,   33,   41,   42,   43,
   37,   45,   59,   47,   40,   42,   43,   43,   45,   45,
   47,    1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   33,   -1,   59,   60,   37,   62,   -1,   33,   41,   42,
   43,   37,   45,   -1,   47,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   40,   41,   -1,   43,   60,   45,   62,
   94,   33,   94,   94,   60,   37,   62,   94,   -1,   -1,
   42,   43,   37,   45,   -1,   47,   41,   42,   43,   37,
   45,   -1,   47,   41,   42,   43,   -1,   45,   60,   47,
   62,   94,   -1,   -1,   59,   60,   -1,   62,   94,   -1,
   -1,   59,   60,   37,   62,   -1,   -1,   41,   42,   43,
   37,   45,   -1,   47,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   94,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   59,   60,   -1,   62,   41,   42,   43,   -1,
   45,   -1,   47,   41,   42,   43,   -1,   45,   41,   47,
   43,   -1,   45,   -1,   59,   60,   41,   62,   43,   -1,
   45,   59,   60,   41,   62,   -1,   59,   60,   41,   62,
   -1,   -1,   41,   -1,   59,   60,   41,   62,   -1,   -1,
   41,   59,   60,   -1,   62,   41,   59,   60,   -1,   62,
   59,   60,   -1,   62,   59,   60,   33,   62,   59,   60,
   37,   62,   -1,   59,   60,   42,   62,   33,   -1,   -1,
   47,   37,   -1,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,
   -1,  257,  258,  259,  261,  262,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,  261,  262,
  263,   -1,   -1,   -1,   -1,  261,  262,  263,   94,   -1,
  257,  258,  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  262,  263,   -1,   -1,   -1,   -1,  261,  262,  263,   -1,
   -1,   -1,   -1,  261,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,
   -1,   -1,   -1,   -1,  261,  262,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,   -1,
   -1,   -1,   -1,  261,  262,  263,   -1,   -1,  261,  262,
  263,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,   -1,
   -1,   -1,   -1,  261,  262,  263,   -1,   -1,  261,  262,
  263,   -1,  261,  262,  263,   -1,  261,  262,  263,   -1,
  261,  262,  263,   -1,   -1,  261,  262,  263,    5,    6,
    7,   -1,   -1,   10,   11,   -1,   -1,   -1,   -1,   16,
   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"NUMBER","VAR","BLTIN","UNDEF","LTE","GTE","NEQ",
"UNARYPLUS","UNARYMINUS",
};
char *yyrule[] = {
"$accept : statement",
"statement :",
"statement : statement asgn ';'",
"statement : statement expr ';'",
"asgn : VAR '=' expr",
"expr : NUMBER",
"expr : VAR",
"expr : asgn",
"expr : BLTIN '(' expr ')'",
"expr : BLTIN '(' ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '^' expr",
"expr : '(' expr ')'",
"expr : '+' expr",
"expr : '-' expr",
"expr : expr '!'",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr LTE expr",
"expr : expr GTE expr",
"expr : expr NEQ expr",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 71 "grammar.y"

#include <stdio.h>
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
#line 354 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
#line 27 "grammar.y"
{ 
  symbol *s; s = lookup("p"); 
  if (!s) 
    execerr("cannot find p", NULL);
  s->u.val = yyvsp[-1].val; printf("  %.8g\n", yyvsp[-1].val);
}
break;
case 4:
#line 35 "grammar.y"
{ 
  if ( isreadonly(yyvsp[-2].sym->name) ) 
    execerr("readonly variable", yyvsp[-2].sym->name);
  yyval.val = yyvsp[-2].sym->u.val = yyvsp[0].val; yyvsp[-2].sym->type = VAR;
  }
break;
case 6:
#line 43 "grammar.y"
{ 
  if (yyvsp[0].sym->type == UNDEF) 
    execerr("undefined variable", yyvsp[0].sym->name);
  yyval.val = yyvsp[0].sym->u.val;
}
break;
case 8:
#line 49 "grammar.y"
{ yyval.val = (*(yyvsp[-3].sym->u.ptr))(yyvsp[-1].val); }
break;
case 9:
#line 50 "grammar.y"
{ yyval.val = (*(yyvsp[-2].sym->u.ptr))(); }
break;
case 10:
#line 51 "grammar.y"
{ yyval.val = yyvsp[-2].val + yyvsp[0].val; }
break;
case 11:
#line 52 "grammar.y"
{ yyval.val = yyvsp[-2].val - yyvsp[0].val; }
break;
case 12:
#line 53 "grammar.y"
{ yyval.val = yyvsp[-2].val * yyvsp[0].val; }
break;
case 13:
#line 54 "grammar.y"
{ 
  if (yyvsp[0].val == 0.0) 
    execerr("division by zero", NULL);
  yyval.val = yyvsp[-2].val / yyvsp[0].val; }
break;
case 14:
#line 58 "grammar.y"
{ yyval.val = (int) yyvsp[-2].val % (int) yyvsp[0].val; }
break;
case 15:
#line 59 "grammar.y"
{ yyval.val = dpow(yyvsp[-2].val, yyvsp[0].val); }
break;
case 16:
#line 60 "grammar.y"
{ yyval.val = yyvsp[-1].val; }
break;
case 17:
#line 61 "grammar.y"
{ yyval.val = yyvsp[0].val; }
break;
case 18:
#line 62 "grammar.y"
{ yyval.val = -yyvsp[0].val; }
break;
case 19:
#line 63 "grammar.y"
{ yyval.val = dfact(yyvsp[-1].val); }
break;
case 20:
#line 64 "grammar.y"
{ yyval.val = yyvsp[-2].val < yyvsp[0].val ? 1 : 0; }
break;
case 21:
#line 65 "grammar.y"
{ yyval.val = yyvsp[-2].val > yyvsp[0].val ? 1 : 0; }
break;
case 22:
#line 66 "grammar.y"
{ yyval.val = yyvsp[-2].val <= yyvsp[0].val ? 1 : 0; }
break;
case 23:
#line 67 "grammar.y"
{ yyval.val = yyvsp[-2].val >= yyvsp[0].val ? 1 : 0; }
break;
case 24:
#line 68 "grammar.y"
{ yyval.val = yyvsp[-2].val != yyvsp[0].val ? 1 : 0; }
break;
#line 628 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
