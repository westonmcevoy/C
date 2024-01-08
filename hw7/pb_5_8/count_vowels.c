#include <stdio.h>
#include <assert.h>
#include <stddef.h>
int count_vowels(char str){
    int acount = 0; int ecount = 0; int icount = 0; int ocount = 0; int ucount = 0;
    while(scanf("%c",&str) != EOF){ 
        if((str == 'a') || (str == 'A')){acount++;}
        if((str == 'e') || (str == 'E')){ecount++;}
        if((str == 'i') || (str == 'I')){icount++;}
        if((str == 'o') || (str == 'O')){ocount++;}
        if((str == 'u') || (str == 'U')){ucount++;}
    }
    printf("%d\n", acount);
    printf("%d\n", ecount);
    printf("%d\n", icount);
    printf("%d\n", ocount);
    printf("%d\n", ucount);
    return 0;
    }
int main(){
    char str = '0';
    return count_vowels(str);
}
