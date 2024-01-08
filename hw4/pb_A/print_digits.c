#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int printDecimalDigits(int n){
    printf("\n");
    if(n <= 0){return(-1);}
    while(n > 10){
            printf("%d\n", (n%10));
            n = n/10;
        }
    printf("%d\n", (n));
    printf("\n");
    return 0;
    }

int main(){
    int test = 0;
    test = printDecimalDigits(124);
    printf("%d\n", (test));
    
    int test1 = 0;
    test1 = printDecimalDigits(12928);
    printf("%d\n", (test1));
    
    int test2 = 0;
    test2 = printDecimalDigits(13);
    printf("%d\n", (test2));
}