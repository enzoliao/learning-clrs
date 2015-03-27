#include<stdio.h>
#include<limits.h>
void extended_bottom_up_cut_rot(int *r, int *s, int *p, int n)
{
    r[0] = s[0] = 0;
    int i,j,q;
    for(i = 1; i < n; i++)
    {
        q = INT_MIN;
        for(j = 1; j <= i; j++)
        {
            if(q < p[j] + r[i-j])
            {
                q = p[j] + r[i -j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
}
void print_out(int *s, int *p, int n)
{
    int i,j;
    for(i = 1; i < n; i++)
    {
        printf("%d\t",p[i]);
        j = i;
        while(j)
        {
            printf("%d ",s[j]);
            j -= s[j];
        }
        printf("\n");
    }
}
main()
{
    #define N 11
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int r[N], s[N];
    extended_bottom_up_cut_rot(r,s,p,N);
    print_out(s,p,N);
}
