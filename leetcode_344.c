#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void reverseString(char* s, int sSize){
    int mid=sSize/2;
    int index=0;
    
    while(index!=mid){
        swap(&s[index], &s[sSize-1-index]);
        index++;
    }
}

int main(){
    char a[]="hello";
    int n=strlen(a);
    reverseString(a, n);
    printf("%s\n", a);
}