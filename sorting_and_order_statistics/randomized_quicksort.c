#include<stdio.h>
#include<time.h>
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
int randomized_partition(int *a, int p, int r)
{
    srand(time(NULL));
    int i;
    i = rand()%(r - p + 1) + p;
    swap(a, i, r);
    return partition(a, p, r);
}
void randomized_quicksort(int *a, int p, int r)
{
    int q;
    if(p < r)
    {
        q = randomized_partition(a, p, r);
        randomized_quicksort(a, p, q-1);
        randomized_quicksort(a, q+1, r);
    }
}
main()
{
    int a[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    randomized_quicksort(a, 0, 7);
    int i;
    for(i = 0; i < 8; i ++) printf("%d ",a[i]);
}
