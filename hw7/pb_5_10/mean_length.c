#include <stdio.h>
#include <assert.h>
#include <stddef.h>

    

int main(int argc, char** argv){
    if(argc<2){return -1;}
    char test[10];
    int len = 0;
    int i;
    for(i=1;i<argc;i++){
        int count = 0;
        sscanf(argv[i],"%s", test);
        while(test[count]){
            count++;
        }
        len = len + count;
    }
printf("%d\n", len/(argc -1));
return 0;
}