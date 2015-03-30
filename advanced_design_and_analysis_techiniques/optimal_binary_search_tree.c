#include<stdio.h>
#include<limits.h>
#define N 5
void optimal_bst(float *p, float *q, int n, float (*e)[N+1], int (*root)[N])
{
    float w[N][N];
    int i,j,k;
    float t;
    for(i = 0; i <= N; i++)
    {
        e[i][i] = w[i][i] = q[i];
    }
    for(i = 0; i < N; i++)  root[i][i] = i;
    for(j = 1; j <= N; j++) //(i,i) 表示空 (i,i+1) 表示只有i
    {
        for(i = j - 1; i >= 0; i--)
        {
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j-1] + q[j] + p[j-1];
            for(k = i; k < j; k++)
            {
                t = e[i][k]+e[k+1][j] + w[i][j];
                if(t < e[i][j])
                {
                    e[i][j] = t;
                    root[i][j-1] = k;
                }
            }
            printf("(%d,%d):%d\n",i,j-1,root[i][j-1]);
        }
    }

}
void construct_optimal_bst(int (*root)[N],int i,int j)
{
    int k = root[i][j];
    if(i < j)
    {       if(k > i)//whether it's out of range.
            {
                printf("%d is the left child of %d\n",root[i][k-1],k);
                construct_optimal_bst(root,i,k-1);
            }
            if(k < j)
            {
                printf("%d is the right child of %d\n",root[k+1][j],k);
                construct_optimal_bst(root,k+1,j);
            }


    }
}
main()
{
    float p[N] = {0.15, 0.10, 0.05, 0.10, 0.20};
    float q[N + 1] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    float e[N+1][N+1];
    int root[N][N];
    optimal_bst(p,q,N,e,root);
    printf("the root is %d\n",root[0][N-1]);
    construct_optimal_bst(root,0,N-1);
}
