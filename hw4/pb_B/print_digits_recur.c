#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int printDigitsRecur(int n){
    printf("\n");
    if(n/10){
        printDigitsRecur(n/10);
    }
    printf("%d\n", (n%10));
    return(0);
}

int printDecimalDigits(int n){
    printf("\n");
    if(n <= 0){return(-1);}
    if(n > 0){
            printDigitsRecur(n);
        }
    printf("\n");
    return(0);
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