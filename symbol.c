#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "y.tab.h"

void execerr(char *, char *);

static symbol *symlist = 0;

symbol *lookup(char *s)
{
  symbol *sp;

  for (sp = symlist; sp; sp = sp->next)
    if ( !strncmp(sp->name, s, SYMSIZE) ) return sp;
  return 0;
}

void *xmalloc(unsigned int n)
{
  void *p; p = malloc(n); if (!p) execerr("out of memory", NULL);
  return p;
}

symbol *install(char *s, int t, double d)
{
  symbol *sp;

  /* allocate space for pointer and symbol name */
  sp = xmalloc(sizeof *sp); sp->name = xmalloc( strlen(s) + 1 );
  strncpy(sp->name, s, SYMSIZE); sp->type = t; sp->u.val = d;
  /* update symlist */
  sp->next = symlist; symlist = sp; return sp;  
}

