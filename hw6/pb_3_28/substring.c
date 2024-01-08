#include <assert.h>
#include <stdio.h>
#include <stddef.h>

int substring(char * string, char * substr){
    if((string == NULL) || (substr == NULL)){return 0;}
    int i;
    for(i=0;substr[i]!='\0';++i){}    //finds length of substr
    int k = i;
    int j = 0;
    for(i=0;string[i]!='\0';++i){
        if(string[i] == substr[j]){   //checks if element i of string is the same as that of substr
            ++j;                      //j is incremented in order to see if the next value of string is in accordance
        }
        else if((j != k) & (string[i] != substr[j])){   //if next value is not in string then cancel check and restart
                j = 0;
        }                  
        
    }
    if(j == k){return 1;}             //if the amount of times substr is incremented = length, than substr is in string
    return 0;
}

int main(){
    int cor = substring("Apple", "ppl");
    assert(cor == 1);
    
    cor = substring("Wonderland", "derl");
    assert(cor == 1);
    
    cor = substring("CU Boulder", "U Boul");
    assert(cor == 1);
    
    cor = substring("Runnnnnnn", "unnnnn");
    assert(cor == 1);
    
    cor = substring("How are you?", "Hello");
    assert(cor == 0);
    
    cor = substring("aloaloalo", "ao");
    assert(cor == 0);
}