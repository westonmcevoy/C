#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int vectorSum(int x[], int y[], int n, int sum[]){
    if((x == NULL) | (y == NULL) | (sum == NULL)){return -1;}
    if(n <= 0){return -2;}
    int i;
    for(i=0;i<n;++i){
        sum[i] = x[i] + y[i];
        printf("%d\n", sum[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    int x[] = {1,2,3};
    int y[] = {2,2,2};
    int sum[3];
    vectorSum(x,y,3,sum);
    
    int a[] = {1,29,3};
    int b[] = {10,23,22};
    int sum2[3];
    vectorSum(a,b,3,sum2);
}