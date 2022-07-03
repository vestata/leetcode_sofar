#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int *arr=(int*)malloc(n * sizeof(int));
    arr[0]=1;
    arr[1]=2;
    for (int i = 2; i < n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}

int main(){
    int n1=2;
    int n2=3;
    int n3=6;
    printf("%d\n", climbStairs(n1));
    printf("%d\n", climbStairs(n2));
    printf("%d\n", climbStairs(n3));
}