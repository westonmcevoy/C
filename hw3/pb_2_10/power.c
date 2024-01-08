#include <assert.h>
#include <stdlib.h>
#include <math.h>

int power(int a, int n, int * p){
    if(p == NULL || n < 0){
        return(-1);
    }
    if(n == 0){
        *p = 1;
        return(0);
    }
    if(n == 1){
        *p = a;
        return(0);
    }
    int i;
    int s = a;
   for(i=1;i<n;++i){
       s = s*a;
   } 
    *p = s;
    return(0);
}
int main(){
int x = 3, y = 1, pow = 0;
power(x, y, &pow);
assert(pow == 3);
    
x = 3, y = 5, pow = 0;
power(x, y, &pow);
assert(pow == 243);
    
x = 4, y = 4, pow = 0;
power(x, y, &pow);
assert(pow == 256);
}