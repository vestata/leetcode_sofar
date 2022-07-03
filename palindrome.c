#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
bool palindrome(char* s)
{
    int length = strlen(s);
    for (int i=0; i<length/2; ++i)
        if (s[i] != s[length - 1 - i])
            return false;
    return true;
}

int main(){
    char arr[]="babab";
    int n=palindrome(arr);
    printf("%d\n",n);
    return 0;
}
*/

int max (int x, int y) { return (x > y)? x : y; }
 