#include "stdio.h"

main()
{ long f[100],i;
 f[1]=1;f[2]=1;
  for(i=3;i<=100;i++)
    f[i]=f[i-1]+f[i-2];
  printf("%ld",f[100]);
}
