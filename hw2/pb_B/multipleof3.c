#include <assert.h>
#include <stdlib.h>

int multipleof3(int a){
    int r = 0;
    r = a%3;
    if(r == 0){
        return(1);
    }
    else{
        return(0);
    }
    
    
}
int main(){
    int i = 3;
    int o = 0;
    while(i < 30){
        o = multipleof3(i);
        assert(o == 1);
        i = i + 3;
    }
    i = 4;
    while(i < 30){
        o = multipleof3(i);
        assert(o == 0);
        i = i + 3;
    }
}