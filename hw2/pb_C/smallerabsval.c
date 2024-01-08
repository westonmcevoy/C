#include <assert.h>
#include <stdlib.h>

int smallerabsval(int x, int y){
    int a = 0;
    int b = 0;
    if(x < 0){
        a = x*-1; 
    }
    else{
        a = x;
    }
    if(y < 0){
        b = y*-1; 
    }
    else{
        b = y;
    }
    if(a < b){
        return(x);
    }
    else if(b < a){
        return(y);
    }
    else if(a == b){
        if(x < y){
            return(y);
        }
        else{
            return(x);
        }
    }
    return 0;
}
int main(){
    assert(smallerabsval(-3,2)==2);
    assert(smallerabsval(3,-2)==-2);
    assert(smallerabsval(-3,3)==3);
    assert(smallerabsval(5,5)==5);
    assert(smallerabsval(-3,-3)==-3);
}