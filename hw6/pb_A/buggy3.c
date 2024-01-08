#include <stdio.h>
#include <assert.h>
#include <stddef.h>

/* Computes a to the n, placing answer in the target of p,
and returns an error code. */
int power(int a, int n, int *p){
    if(n < 0 || p == NULL) return -1;   
    int i = 0;
    int pow = 1;
    while(i < n){
        pow = pow * a;
    }
    *p = pow;
    return 0;
}

/* Computes the aritmetic mean of the array a, of length len,
placing the result in the target of mn, and returns an error code. */
int mean(int const * a, int len, int * mn) {
	int i;
	if(a==NULL || mn==NULL || len <= 0){return -1;}

	int tot = 0;
	for (i = 0; i < len; i++){
		tot += a[i];
    }
	*mn = tot / len;
	return 0;
}

/* Unit tests the above two functions */
int main(){
    int a = 2, n = 3, ans, err;
    err = power(a,n,&ans);
    assert(err == 0);
    assert(ans == 8);
	
	int arr1[] = {1,1,1};
	int arr2[] = {2,2,2};
	int arr3[] = {1,2,3};
	int mn;
    err = mean(arr1,3,&mn);
	assert(mn==1);
    err = mean(arr2,3,&mn);
	assert(mn==2);
    err = mean(arr3,3,&mn);
	assert(mn==2);
	
    return 0;
}
