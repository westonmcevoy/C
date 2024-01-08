#include <assert.h>
#include <stdlib.h>

int while_product(int n,int* ans){
    assert(n > 0);
    int p = 1;
    int i = 1;
    while(i < n){
        ++i;
        p = p * i;
    }
    *ans = p;
    return(0);
}

int main(){
    int n = 4;
    int ans = 0;
    while_product(n,&ans);
    assert(ans == 24);
    
    n = 5;
    while_product(n,&ans);
    assert(ans == 120);
}