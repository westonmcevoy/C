#include <stdio.h>
#include <assert.h>
#include <stddef.h>

int range(int len, int* str, int* min, int* max){
    if((str == NULL)||(str == 0)){return -1;}
    int i;
    for(i=0;i<len;++i){
        if(str[i]>*max){
            *max = str[i];
        }
        if(str[i]<*min){
            *max = str[i];
        }
    }
    printf("%d\n", *max-*min);
    return 0;   
}

int main(int argc, char** argv){
    if(argc<=2){return -1;}
    int str[argc-1];
    int i;
    for(i=1;i<argc;++i){
        if(!sscanf(argv[i],"%d",&str[i-1])){
            return -1;
        }
    }
    int max = str[0];
    int min = str[0];
    return range(argc-1,str,&min,&max);
}