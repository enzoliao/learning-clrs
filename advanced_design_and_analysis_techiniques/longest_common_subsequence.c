#include<stdio.h>
#include<stdlib.h>
#define M 8
#define N 7
#define MAX 10
#define BIAS 1
#define UP 2
#define LEFT 3
void lcs_length(char *x,char *y,int (*b)[N], int (*c)[N])
{
    int i,j,k;
    for(i = 0; i < M; i++) b[i][0] = c[i][0] = 0;
    for(i = 0; i < N; i++) b[0][i] = c[0][i] = 0;
    for(i = 1; i < M; i++)
    {
        for(j = 1; j < N; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = BIAS;
            }
            else
            {
                if(c[i - 1][j] >= c[i][j - 1])//May have two equal ans
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UP;
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = LEFT;
                }
            }
        }
    }
}
int print_lcs(int (*b)[N], char *x,int i,int j)
{
    if(i == 0 || j == 0) return 0;
    if(b[i][j] == BIAS)
    {
        print_lcs(b,x,i-1,j-1);
        printf("%c %d,%d\n",x[i-1],i,j);
    }
    else
    {
        if(b[i][j] == LEFT)
        {
            print_lcs(b,x,i,j-1);
        }
        else print_lcs(b,x,i-1,j);
    }
}
main()
{
    char x[MAX] = "ABCBDAB";
    char y[MAX] = "BDCABA";
    int b[M][N],c[M][N];
    lcs_length(x,y,b,c);
    int i,j;
    for(i = 0; i< M; i++)
    {
        for(j = 0; j< N; j++)   printf("%2d ",c[i][j]);
        printf("\n");
    }
    print_lcs(b,x,M-1,N-1);
}
