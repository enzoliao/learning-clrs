#include<stdio.h>
#include<stdlib.h>
void count_sort(int *a, int *b, int length, int k)
{
    int *c = malloc(sizeof(int)*k);
    int i,j;
    for(i = 0; i < k; i++)  c[i] = 0;
    for(j = 0; j < length; j++) c[a[j]] = c[a[j]] + 1;
    for(i = 1; i < k; i++)  c[i] += c[i - 1];
    for(j = length - 1; j >= 0; j--){
        b[c[a[j]] - 1] = a[j];// -1 is necessary here.
        c[a[j]]-=1;
        //for(i = 0; i < 8; i++) printf("%d ",b[i]);
        //printf("\n");
    }
}
main()
{
    int a[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int b[8];
    int i;
    for(i = 0; i < 8; i++) b[i] = 0;
    count_sort(a,b,8,6);//Suppose a is 0 -> k, pass k+1 to the function.
    for(i = 0; i < 8; i++) printf("%d ",b[i]);
}
