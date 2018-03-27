#define NUMBER 257
#define VAR 258
#define BLTIN 259
#define UNDEF 260
#define LTE 261
#define GTE 262
#define NEQ 263
#define UNARYPLUS 264
#define UNARYMINUS 265
typedef union { double val; symbol *sym; } YYSTYPE;
extern YYSTYPE yylval;
