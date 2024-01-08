#include <assert.h>
#include <stdlib.h>

int minmax(int a, int b, int* min, int* max){
    if(a > b){
        *max = a;
        *min = b;
    }
    else if(b > a){
        *max = b;
        *min = a;
    }
    else if(a == b){
        return(1);
    }
return(0);
}

int main(){
    int a = 39;
    int b = 15;
    int min = 0;
    int max = 0;
    minmax(a,b,&min,&max);
    assert(min == b);
    assert(max == a);
    
    a = 2;
    b = 3;
    minmax(a,b,&min,&max);
    assert(min == a);
    assert(max == b);
    
    a = 1;
    b = 1;
    int x = 0;
    x = minmax(a,b,&min,&max);
    assert(x == 1);
}