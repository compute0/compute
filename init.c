#include <string.h>
#include <math.h>
#include "symbol.h"
#include "y.tab.h"

extern double drand();
extern double dlog();
extern double dlog10();
extern double dexp();
extern double dsqrt();
extern double dinteger();
extern double dfact();
extern double pop();
extern void init_stack();

static struct {
  char *name;
  double cval;
} cons[] = {
  { "pi", 3.14159265358979323846 },
  { "e", 2.71828182845904523536 },
  { "deg", 57.29577951308232087680 },
  { "p", 0.0 },
  { 0, 0 }
};

static struct {
  char *name;
  double (*func)();
} builtins[] = {
  { "sin", sin },
  { "cos", cos },
  { "atan", atan },
  { "log", dlog },
  { "log10", dlog10 },
  { "exp", dexp },
  { "sqrt", dsqrt },
  { "int", dinteger },
  { "abs", fabs },
  { "rand", drand },
  { "fact", dfact },
  { "pop", pop },
  { 0, 0 }
};

int isreadonly(char *s)
{
  int i;
  for (i=0; cons[i].name; ++i) 
    if (! strncmp(s,cons[i].name,SYMSIZE) ) return 1;

  return 0;
}


void init(void)
{
  int i; symbol *s;
  init_stack();

  for (i=0; cons[i].name; ++i)
    install(cons[i].name, VAR, cons[i].cval);

  for (i=0; builtins[i].name; ++i) {
    s = install(builtins[i].name, BLTIN, 0.0);
    s->u.ptr = builtins[i].func;
  }
}
