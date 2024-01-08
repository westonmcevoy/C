#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int xvowel(char * in, char * out){
    if((in == NULL) || (out == NULL) || (!in) || (!out)){return -1;}
    int i;
    int j=0;
    for(i=0;in[i]!='\0';++i){
        if((in[i] != 'a') & (in[i] != 'e') & (in[i] != 'i') & (in[i] != 'o') & (in[i] != 'u') & (in[i] != 'A') & (in[i] != 'E') & (in[i] != 'I') & (in[i] != 'O') & (in[i] != 'U')){
            out[j] = in[i];
            ++j;
        }
    }
return 0;
}

int main(){
char str[] = "Hello universe!";
char out[32];
int err = xvowel(str, out);
assert(!err);
printf("%s\n%s\n", str, out);
}
