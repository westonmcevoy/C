#include <stdio.h>
#include <assert.h>
#include <stddef.h>

int m_n_sum(int m, int n){
    if(m>n){return -1;}
    int i;
    int sum = m;
    for(i=1;i<=n-m;++i){
        sum = sum + m + i;
    }
    printf("%d\n", sum);
    return 0;
}

int main(int argc, char** argv){
    if(argc>3){
        return -1;
    }
    int m;
    if(!sscanf(argv[1],"%d",&m)){
        return -1;
    }
    int n;
    if(!sscanf(argv[2],"%d",&n)){
        return -1;
    }
    return m_n_sum(m,n);
}