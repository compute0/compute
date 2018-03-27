#ifndef SYMBOL_H
#define SYMBOL_H

#define SYMSIZE 15

typedef struct symbol {
  char *name;
  short type;
  union {
    double val;
    double (*ptr)();
  } u;
  struct symbol *next;
} symbol;

symbol *install();
symbol *lookup();

#endif
