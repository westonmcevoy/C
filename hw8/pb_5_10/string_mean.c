#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <ctype.h>

int main(){
    char store = '0';
    int len = 0;
    int words = 1;
        while(scanf("%c",&store)!=EOF){ 
            if(!isspace(store)){len++;}
            else{words++;}
        }
int mean = (len/words);
printf("Len is:%d\n",len);
printf("Words is:%d\n",words);
printf("Mean is:%d\n",mean);
return 0;
}
        
        





/*int main(int argc, char** argv){
    if(argc<2){return -1;}
    char test[10];
    int len = 0;
    for(int i=1;i<argc;i++){
        sscanf(argv[i],"%s",test);
        while(!isspace(test[i-1])){
            len++;
        }
    }
char store[len];
    for(int i=1;i<argc;i++){
        sscanf(argv[i],"%s",test);
    for(int k=1;test[i-1]!='\0';k++){
        while(sscanf(argv[i],"%c", store) != EOF);
    }
}
printf("%s", store);
return 0;
}
*/