#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int unzip(int * a, int * b, int * c, int n){
    if((a == 0) | (b == 0) | (c == 0)){return -1;}
    int i;
    for(i=0;i<n;++i){
        a[i] = c[i];
        b[i] = c[i+n];
    }
    return 0;
}

int main(){
    int a[3];
    int b[3];
    int c[] = {1,2,3,4,5,6};
    int n = 3;
    int i;
    unzip(a,b,c,n);
    
    for(i=0;i<n;++i){
        printf("%d\n",a[i]);
    }
    printf("\n");
    for(i=0;i<n;++i){
        printf("%d\n",b[i]);
    }
    printf("\n");
    
    int e[3];
    int f[3];
    int g[] = {12,34,56,8,90,1};
    unzip(e,f,g,n);
    
    for(i=0;i<n;++i){
        printf("%d\n",e[i]);
    }
    printf("\n");
    for(i=0;i<n;++i){
        printf("%d\n",f[i]);
    }
}