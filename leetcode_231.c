#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    if(n==1) return true;
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int num1=1;
    int num2=16;
    int num3=3;
    printf("%d\n", isPowerOfTwo(num1));
    printf("%d\n", isPowerOfTwo(num2));
    printf("%d\n", isPowerOfTwo(num3));

    return 0;
}