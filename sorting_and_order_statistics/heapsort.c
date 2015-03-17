#include<stdio.h>
#include<math.h>
int parent(int i)
{
    return (i - 1)>> 1;
}
int left(int i)
{
    return 2*i + 1;
}
int right(int i)
{
    return 2*i + 2;
}
void max_heapify(int *a, int i, int size)
{
    int r,l,temp,largest;
    r = right(i);
    l = left(i);
    if(r < size && a[r] > a[i]){
        largest = r;
    }
    else largest = i;
    if(l < size && a[l] > a[largest]) largest = l; //The order between the right and the left doesn't matter at all. Just get the largest.
    if(!(largest == i)){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, size);
    }
}
void build_max_heap(int *a, int length)
{
    int i;
    for(i = length/2 -1; i >= 0; i--)   max_heapify(a, i, length);
}
void print_heap(int *a,int length)
{
    int i,j,k;
    k = 1;
    for(i = j =0; i < length ; i++)
    {
        printf("%d ",a[i]);
        if(i == j){
            printf("\n");
            j += pow(2,k);
            //printf("--j = %d\n",j);
            k++;
        }
    }
    printf("\n");
}
void heap_sort(int *a, int length)
{
    build_max_heap(a, length); // make an array become a heap.
    int i,temp,len;
    len = length;
    for(i = length -1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp; //exchange a[i] with a[0]
        len--;// pop the max one.
        max_heapify(a, 0, len);//heapify.
    }
}
main()
{
    int a[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    print_heap(a, 10);
    //build_max_heap(a, 10);
    heap_sort(a,10);
    print_heap(a, 10);
}
