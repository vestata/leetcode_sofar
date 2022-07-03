#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "quicksortstring.h"

/*
//Runtime: 1120 ms; Memory Usage: 5.9 MB !!速度太慢!!
bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t))
        return false;
    quickSort(s, 0, strlen(s)-1);
    quickSort(t, 0, strlen(t)-1);
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i]!=t[i])
            return false;
    }
    return true;
}
*/

//google完發現使用hash table 效率比較高
bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t))
        return false;
    int letter[26]={0};
    int indexs;
    int indext;
    for (int i = 0; s[i]!='\0'; i++)
    {
        indexs=s[i]-'a';
        letter[indexs]++;
        indext=t[i]-'a';
        letter[indext]--;
    }
    for (int j = 0; j < 26; j++)
    {
        if(letter[j]!=0)
            return false;
    }
    return true;
}

int main(){
    char s1[]="anagram";
    char t1[]="nagaram";
    char s2[]="rat";
    char t2[]="car";
    char s3[]="a";
    char t3[]="ab";
    printf("%d\n", isAnagram(s1, t1));
    printf("%d\n", isAnagram(s2, t2));
    printf("%d\n", isAnagram(s3, t3));
    return 0;
}