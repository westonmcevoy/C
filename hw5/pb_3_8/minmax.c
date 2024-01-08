#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int minmax(int * a, int n, int * min, int * max){
    if((a == NULL) | (min == NULL) | (max == NULL)){return -1;}
    if(n <= 0){return -2;}
    int i;
    *min = a[0];
    *max = a[0];
    for(i=1;i<n;++i){
        if(a[i] <= *min){
            *min = a[i];
        }
        else if(a[i] >= *max){
            *max = a[i];
        }
    }
    return 0;
}

int main(){
    int a[] = {1,5,29,-40};
    int n = 4;
    int min = 0;
    int max = 0;
    minmax(a,n,&min,&max);
    assert(min == -40);
    assert(max == 29);
    
    int b[] = {-1,-50,-290,-40};
    n = 4;
    min = 0;
    max = 0;
    minmax(b,n,&min,&max);
    assert(min == -290);
    assert(max == -1);
}
