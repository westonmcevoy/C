// The following code is a buggy implementation
// of Exercise 1.19 in the book (we went over it in
// class last lab).  
// Using gcc, work to eliminate
// all compilation errors and warnings in this code,
// then verify it runs correctly.  Your solution to
// this problem will be the corrected buggy.c file

#include <assert.h>
#include <stdlib.h>

void swap(int* x, int* y){
    assert (x != NULL);
    assert (y != NULL);
    int t = *x;
    int* s = y;
    *x = *s;
    *y = t;
    }
int main(){
    int a = 0;
    int b = 1;
    swap(&a, &b);
    assert(a == 1);
    assert(b == 0);
    return 0;
}