#include<stdio.h>
#include<limits.h>
void merge(int *a, int p, int q, int r){
	int m,n,i,j,k;
	m = q - p + 1;
	n = r - q;
	int left[100],right[100];
	for(i = 0; i < m; i++){
		left[i] = a[p + i];
	}
	for(j = 0; j < n; j++){
		right[j] = a[q + 1 + j];
	}
	left[m] = right[n] = INT_MAX;
	for(i = j = 0, k = p; k <= r; k++){
		if(left[i] < right[j]){
			a[k] = left[i];
			i++;
		}
		else{
			a[k] = right[j];
			j++;
		}
	}
}
void merge_sort(int *a, int p, int r){
	int q;
	if(p < r){
		q = (p + r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}
main(){
	int a[8] = {5, 2, 4, 7, 1, 3, 2, 6 };
	merge_sort(a, 0, 7);
	int i;
	for(i = 0; i < 8; i++){
		printf("%d ", a[i]);
	}
}
