#include <stdio.h>
void Perm(int* list, int n, int k)
{
    if (k==n-1)
    {
        for (int i = 0; i < n; i++)
        printf("%d", list[i]);
        printf("\n");
    }
    else
    {
        for (int i = k; i < n; i++)
        {
            int temp;
   
            temp = list[k], list[k] = list[i], list[i] = temp;
            Perm(list, n, k+1);
  
        }
    }
}
 
int main()
{
    int array[128] = {0};
    int n = 0, i = 0;    
    scanf("%d", &n);
    for (i = 0; i < n; i++) array[i] = i+1;
    Perm(array, n, 0);
    return 0;
}
