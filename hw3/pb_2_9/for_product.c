#include <assert.h>
#include <stdlib.h>

int for_product(int n, int* ans){
    assert(n > 0);
    int i;
    int p = 1;
    for(i=0;i<n;++i){
        p = p * (i+1);
    }
    *ans = p;
    return(0);
}
int main(){
    int n = 4;
    int ans = 0;
    for_product(n,&ans);
    assert(ans == 24);
    
    n = 7;
    for_product(n,&ans);
    assert(ans == 5040);
}