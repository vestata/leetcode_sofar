#include <stdio.h>
#include <string.h>
/*
char findTheDifference(char * s, char * t){
    if(strlen(s)==0)
        return *t;
    int index=0;
    while(index!=strlen(t)){
        if(t[index]!=s[index])
            return *(t+index);
        index++;
    }
    return *(t+index);
}
//發現原來題目給的string 不一定是sorted
*/
char findTheDifference(char * s, char * t){
    if(strlen(s)==0)
        return *t;
    char res=0;
    for (int i = 0; i < strlen(s); ++i)
    {
        res ^= s[i];
    }
    for(int i=0; i<strlen(t); ++i){
        res ^= t[i];
    }
    return res;
    
}


int main(){
    char s[1000]="asdf";
    char t[1001]="dfsav";
    int n = findTheDifference(s, t);
    printf("%c\n", n);
}