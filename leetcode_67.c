#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a>b)?a:b)
/*
char * addBinary(char * a, char * b){
    int n=max(strlen(a), strlen(b));
    for (size_t i = 0; i < count; i++)
    {
    }
    
}
*/
int main(){
    char a[]="1010";
    char b[]="1011";

    int n=max(strlen(a), strlen(b));
    int carryout=0;
    char sum[n+1];
/*
    for (int i = n-1; i >=0; i--)
    {
        sum[i]=a[i]+b[i]+carryout;
        if(sum[i]>=som)
    }
  */
    for (int i = n-1; i >= 0; i--)
    {
        sum[i]=a[i]+b[i];
    }
    printf("%d\n", n);
    


    return 0;
}