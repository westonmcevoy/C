#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int mean(int * a, int len, int * mn){
    if((len <= 0) | (a == 0) | (mn == 0)){return -1;}
    int sum = 0;
    int i;
    for(i=0;i<len;++i){
        sum = sum + a[i];
    }
    *mn = sum/len;
    return 0;
}

int main(){
    int a[] = {1,1,1};
    int mn = 0;
    int len = 3;
    mean(a,len,&mn);
    assert(mn == 1);
    
    int b[] = {7,5,6};
    mn = 0;
    len = 3;
    mean(b,len,&mn);
    assert(mn == 6);
}