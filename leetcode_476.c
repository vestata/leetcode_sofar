#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
int convertDtoB(int n){
    int bin = 0;
    int rem;
    long i = 1;
    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

int convertBtoD(int n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}

int findComplement(int num){
    if(num==1) return 0;
    int n=convertDtoB(num);
    int i=1;
    int rem;
    int ans=0;
    while(n!=0){
        rem=n%10;
        if(rem==1){
            rem=0;
        }else{
            rem=1;
        }
        n/=10;
        ans+=rem*i;
        i*=10;
    }
    ans=convertBtoD(ans);
    return ans;
}
*/
int findComplement(int num){
    int m=1;
    int output=0;
    do
    {
        if(num%2==0){
            output+=m;
        }
        m*=2;
    } while (num/=2);
    return output;
    
}
int main(){
    printf("%d\n", findComplement(2147483647));
    return 0;
}