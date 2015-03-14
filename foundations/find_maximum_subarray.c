#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct subarray {
	int start;
	int end;
	int sum;
} Array;
typedef Array * Arraypt;
Arraypt max_cross(int *a, int low, int high, int mid)
{
	int left_sum, right_sum, i, sum, max_left, max_right;
	left_sum = right_sum = INT_MIN;
	for(sum = 0, i = mid ; i >= low; i-- )
	{
		sum = sum + a[i];
		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}
	for(sum = 0, i = mid + 1; i <= high; i++ )
	{
		sum = sum + a[i];
		if(sum > right_sum){
			right_sum = sum;
			max_right = i;
		}
	}
    Arraypt cross = (Arraypt )  malloc(sizeof(Array));
    cross -> start = max_left;
    cross -> end = max_right;
    cross -> sum = left_sum + right_sum;
    return cross;
}
Arraypt max_sub(int *a, int low, int high)
{
    Arraypt sub = (Arraypt) malloc(sizeof(Array));
    if(low == high){
        sub -> start = sub -> end = low;
        sub -> sum = a[low];
        return sub;
    }
    else{
        int mid = (low + high)/2;
        Arraypt l,h,c;
        l = max_sub(a, low, mid);
        h = max_sub(a, mid +1,high);
        c = max_cross(a, low, high, mid);
        if((l -> sum > h -> sum ) && ( l -> sum > c -> sum))    return l;
        else{
            if((h -> sum > l -> sum) && ( h -> sum > c -> sum)) return h;
            else return c;
        }
    }
}
main()
{
    int a[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Arraypt cross;
    cross = max_sub(a, 0, 15);
    printf("%d %d %d",cross -> start, cross -> end, cross -> sum);
}


