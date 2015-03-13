#include<stdio.h>
void insert_sort(int *a,int length){
	int i, j, key;
	for( j = 1; j < length; j++)
	{
		key = a[j];
		i = j - 1;
		while( ( i >= 0) && ( a[i] > key)){
			a[i+1] = a[i];
			i-- ;
		}
		a[i+1] = key;
		
		for(i = 0; i < 6; i++){
			printf("%d ", a[i]);
		} 
		printf("\n");
		//this for loop use to put out the test
	}	
}
main(){
	int a[6] = { 5, 2, 4, 6, 1, 3};
	insert_sort(a, 6);
	int i;
}

