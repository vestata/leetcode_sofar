#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n){
    if(n<=0) return false;
    if(n==0) return true;
    while(n!=1){
        if(n%4==0){
            n=n/4;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    printf("%d\n", isPowerOfFour(16));
    printf("%d\n", isPowerOfFour(5));
    printf("%d\n", isPowerOfFour(1));
    return 0;
}