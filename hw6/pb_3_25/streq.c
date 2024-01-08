#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int streq(char * str1, char * str2){
    if((str1 == NULL) || (str2 == NULL)){return 0;}
    int i;
    int j;
    for(i=0;str1[i]!='\0';++i){}   //calculates length of str1 and stores in i
    for(j=0;str2[j]!='\0';++j){}   //calculates length of str2 and stores in j
    if(i != j){return 0;}          //if lengths are different then 0 is returned
    for(i=0;str1[i]!='\0';++i){    //if lengths are the same each value is compared
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str1[] = "Caden";
    char str2[] = "Caden";
    int err = streq(str1,str2);
    assert(err == 1);
    
    char str3[] = "Caden";
    char str4[] = "Caden1";
    err = streq(str3,str4);
    assert(err == 0);
    
    err = streq("LOLOLOLOL","OLOLOLOLO");
    assert(err == 0);
}
