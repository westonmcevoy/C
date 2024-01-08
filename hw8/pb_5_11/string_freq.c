#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <ctype.h>

int printDistribution(int* nOccur, int sz, int nTrials) { 
    if(!nOccur){return -1;}
    int fail = 0;
    int percent = 0;
    for(int i=1;i<=sz;i++){
    if(nOccur[i]==0){
        fail++;
        continue;
    }
    percent = (100 * nOccur[i]) / nTrials;
    printf("%2d percent of words have %d characters", percent, i);
    for(int j=0;j<percent;j++){printf("*");}
    printf("\n");
    }
    if(fail==32){return -1;}
    return 0;
    }

int main(int argc, char** argv){
    char store = '0'; char check[10]; int len = 0; int n = 32; int k = 0; int trials = 0;
    if(argc>1){
        for(int i=1;i<argc;i++){
            sscanf(argv[i],"%s",check);
            if((check[k] == '-') & (check[k+1] == 'h')){
                printf("Type a sentence to see the word count frequency distribution!\n");
            }
            else if((check[k] == '-') & (check[k+1] == 's')){
                if(!(sscanf(argv[i+1],"%d",&n)) || (argc<2)){return -1;}
                if((n>32) || (n<0)){return -1;}
            }
            else if((check[k] == '-') & (!((check[k+1] == 'h') || (check[k+1] == 's')))){return -1;}
        } 
    }
    int nOccur[n+1];
    for(int l=0;l<n+1;l++){
        nOccur[l] = 0;
    }
    while((scanf("%c",&store)!=EOF)){ 
        if(!isspace(store)){len++;}
        else if(len>n){
            nOccur[n]++;
            trials++;
            len = 0;
        }
        else if(len==0){len = 0;}
        else{
            nOccur[len]++;
            trials++;
            len = 0;
        }
    }
return printDistribution(nOccur, n, trials);
}