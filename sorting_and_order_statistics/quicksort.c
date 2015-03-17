#include<stdio.h>
void swap(int *a, int i, int j) //Exchange a[i] with a[j].
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int *a, int p, int r)
{
    int x, i, j;
    x = a[r];
    i = p - 1;
    for(j = p; j < r; j++)
    {
        if(a[j] <= x){
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i+1, r);
    return i+1;
}
void quicksort(int *a, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}
main()
{
    int a[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    quicksort(a, 0, 7);
    int i;
    for(i = 0; i < 8; i ++) printf("%d ",a[i]);
}
