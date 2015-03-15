#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insert_sort(int *a, int *p, int length)
{
	int i, j, key,temp;
	for( j = 1; j < length; j++)
	{
		key = p[j];
		temp = a[j];
		i = j - 1;
		while( ( i >= 0) && ( p[i] > key)){
			a[i+1] = a[i];
			i-- ;
		}
		a[i+1] = temp;
	}
}
void permute_by_sorting(int *a, int length)
{
    int *p = (int *)malloc(sizeof(int) * length);
    int i;
    srand(time(NULL));
    for(i = 0; i< length; i++)
    {
        p[i] = rand()%(length *length *length) + 1;
    }
    insert_sort(a, p, length);
    free(p);
}
void a_print(int *a,int length)
{
    int i;
    for(i = 0; i< length; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void randomize_in_place(int *a, int length)
{
    int i,temp,j;
    for(i = 0; i < length; i++)
    {
        srand(time(NULL));
        j = rand()%(length - i + 1) + i;
        //printf("%d\n",j);
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}
main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    permute_by_sorting(a,10);
    a_print(a,10);
    randomize_in_place(b,10);
    a_print(b,10);
}
