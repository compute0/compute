#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>

extern void execerr();

static unsigned long seed;

static unsigned int r(void)
{
  if (!seed) seed = time(0); 

  seed = seed * 1103515245 + 12345;
  return (unsigned int) (seed/65536) % 32768;
}

static double fact(double x)
{
  unsigned int r = (int) x;
  if (x == 1) return 1;
  
  return (double) r * fact(r - 1);
}

double errcheck(double d, char *s)
{
  if (errno == EDOM) {
    errno = 0;
    execerr(s, "argument out of domain");
  } else if (errno == ERANGE) {
    errno = 0;
    execerr(s, "result out of range");
  }

  return d;
}

double drand(double x)
{
  unsigned int y; y = (unsigned int) x;

  if (y <= 0 || y > UINT_MAX) 
    return (double) r();

  return (double) (r() % y);
}

double dlog(double x)
{
  return errcheck(log(x),"log");
}

double dlog10(double x)
{
  return errcheck(log10(x),"log10");
}

double dexp(double x)
{
  return errcheck(exp(x), "exp");
}

double dsqrt(double x)
{
  return errcheck(sqrt(x), "sqrt");
}

double dpow(double x, double y)
{
  return errcheck(pow(x,y), "exponentiation");
}

double dfact(double x)
{
  return errcheck(fact(x), "factorial");
}

double dinteger(double x)
{
  return (double)(long) x;
}
