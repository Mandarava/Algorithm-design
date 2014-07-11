#include "stdio.h"
long f(int n)
{ if (n==1) return 1;
  if (n==2) return 1;
  return f(n-1)+f(n-2);
}

main()
{ int n=100;
  printf("%ld",f(n));
}
