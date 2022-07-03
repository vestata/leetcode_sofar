#include <stdio.h>
#include <string.h>
/*
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

int lengthOfLastWord(char * s){
    reverseString(s, strlen(s));
    int i=0;
    int count=0;
    while(s[i]==' '){
        i++;
    }
    while(s[i]!=' '){
        i++;
        count++;
    }
    return count;
}
*/


int lengthOfLastWord(char * s){
    int count=0;
    for (int i = strlen(s)-1; i >=0; i--)
    {
        if(s[i]!=' ')
            count++;
        else if(s[i]==' '&& count!=0)
            break;
    }
    return count;
}


int main(){
    char s1[]="Hello World";
    char s2[]="   fly me   to   the moon  ";
    char s3[]="luffy is still joyboy";
    char s4[]="a ";
    char s5[]="ab ";
    int n1=lengthOfLastWord(s1);
    int n2=lengthOfLastWord(s2);
    int n3=lengthOfLastWord(s3);
    int n4=lengthOfLastWord(s4);
    int n5=lengthOfLastWord(s5);
    printf("%d\n", n1);
    printf("%d\n", n2);
    printf("%d\n", n3);
    printf("%d\n", n4);
    printf("%d\n", n5);
    return 0;
}

