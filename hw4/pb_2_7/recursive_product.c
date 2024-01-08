#include <assert.h>
#include <stdlib.h>

int _product(int n){
    if (n == 1){
        return(1);
    }
    return _product(n-1) * n;
}

int product(int n, int * ans){
if (n <= 0 || ans == NULL){
    return -1;  
}
*ans = _product(n);
    return(0);
}

int main(){
    int n = 5;
    int ans = 0;
    product(n, &ans);
    assert(ans == 120);
}