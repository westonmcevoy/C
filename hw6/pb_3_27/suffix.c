#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int suffix(char * str, char * suf){
    if((str == NULL) || (suf == NULL) || (!str)){return 0;}
    int i;
    int j=0;
    for(i=0;str[i]!='\0';++i){}   //calculates length of str and stores in k
    int k = i;
    for(i=k-3;i<k;++i){           //iterates through last three characters of str and stores them in suf
        suf[j] = str[i];
        ++j;
    }
    if((suf[0] == 'i') & (suf[1] == 'n') & (suf[2] == 'g')){    //checks if suf is "ing"
        return 1;
    }
    return 0;
}

int main(){
char str[] = "sailing";
char suf[] = "suf";
int err = suffix(str,suf);
printf("%s\n", suf);
assert(err == 1);

err = suffix("running",suf);
assert(err == 1);
    
err = suffix("winning",suf);
assert(err == 1);
    
err = suffix("funded",suf);
assert(err == 0);
}