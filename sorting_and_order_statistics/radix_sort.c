#include<stdio.h>
#include<stdlib.h>
int power(int a, int time)
{
    int i,j;
    for(i = 0,j = 1; i < time; i++)   j *= a;
    return j;
}
int current(int a, int digit)
{
    int i;
    i = power(10, digit - 1);//Since the pow() in <math.h> return a double, (int) pow(10,2) will give a goddamn 99.
    return (a/i) % 10;
} // current(123,2) = 2.
void count_sort(int *a, int length, int k, int digit)// count_sort which key value is different digit.
{
    int *c = malloc(sizeof(int)*k);
    int *b = malloc(sizeof(int) * length);
    int i,j;
    for(i = 0; i < k; i++)  c[i] = 0;
    for(j = 0; j < length; j++) c[current(a[j],digit)] = c[current(a[j], digit)] + 1;
    for(i = 1; i < k; i++)  c[i] += c[i - 1];
    for(j = length - 1; j >= 0; j--){
        b[c[ current(a[j],digit) ] - 1] = a[j];// -1 is necessary here.
        c[current(a[j],digit)]-=1;
        //for(i = 0; i < 8; i++) printf("%d ",b[i]);
        //printf("\n");
    }
    free(c);
    for(i = 0; i < length; i++){
        a[i] = b[i];
    }
    free(b);
}
main()
{
    int a[7] = {329, 457, 657, 839, 436, 720, 355};
    int i,j;
    for(i = 1; i <= 3; i++){
        count_sort(a, 7, 10, i );
        //for(j = 0; j < 7; j++) printf("%d ",a[j]); //when you copy your code, you are not coding at all.
        //printf("\n");
    }
    for(j = 0; j < 7; j++) printf("%d ",a[j]);
}
