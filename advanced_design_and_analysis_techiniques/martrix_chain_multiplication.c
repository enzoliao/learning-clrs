#include<stdio.h>
#include<limits.h>
#define N 6
martrix_chain_order(int *p, int (*a)[N] , int(*s)[N] ,int n)
{
    int i,j,k,q,temp;
    for(i = 0; i < n; i++)
    {
        a[i][i] = 0;
        if(i<5)
        {
            a[i][i+1] = p[i] * p[i+1] * p[i+2];//Be careful of the array may comes out of range.
            s[i][i+1] = i;
        }
    }
    for(i = 2; i < n; i++)
    {
        for(j = i -2; j >= 0;j--)
        {
            a[j][i] = temp = INT_MAX;
            for(k = j; k <i;k++)
            {
                temp =  a[j][k]+a[k+1][i] +p[j]*p[k+1]*p[i+1];
                if(temp < a[j][i])
                {
                    a[j][i] = temp;
                    s[j][i] = k;
                }
            }
        }
    }
}
print_optimal_parents(int(*s)[N], int i, int j)
{
    if(i == j)  printf("A%d",i);
    else
    {
        printf("( ");
        print_optimal_parents(s,i,s[i][j]);
        print_optimal_parents(s,s[i][j]+1,j);
        printf(" )");
    }
}
main()
{
    int p[N+1] = {30, 35, 15, 5, 10, 20, 25};
    int a[N][N],s[N][N];
    martrix_chain_order(p,a,s,N);
    print_optimal_parents(s,0,5);
}
