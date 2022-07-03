#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int index=0;
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        while(index<strlen(magazine)){
            if(ransomNote[i]==magazine[index]){
                magazine[index]=0;
                index++;
                break;
            }
            if(index==(strlen(magazine)-1))
                return 0;
        }
        index=0;
    }
    return 1;
}

/*
bool canConstruct(char * ransomNote, char * magazine){
    for (int i = 0; i < strlen(a); i++)
    {
        
    }
    
}
*/
int main(){
    char ransomNote[]="aa";
    char magazine[]="ab";
    printf("%d\n", canConstruct(ransomNote, magazine));
    return 0;
}