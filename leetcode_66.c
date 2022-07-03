#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *ret=(int*)malloc(sizeof(int)*digitsSize);
    for (int i = digitsSize-1; i >= 0; i--)
    {
        if(digits[i]<9){
            digits[i]=digits[i]+1;
            break;
        }else{
            digits[i]=0;
        }
    }
    if(digits[0]==0){
        for (int j = 0; j< digitsSize+1; j++)
        {
            ret[j]=0;
        }
        ret[0]=1;
        returnSize=digitsSize+1;
        return ret;
    }else{
        for (int i = 0; i < digitsSize; i++)
        {
            ret[i]=digits[i];
        }
        *return=digitsSize;
        return ret;
    }
}


void printarray(int* arr, int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,2,3};
    printarray(arr, 3);
    plusOne(arr, 3, 3);
    printarray(arr, 3);

    return 0;
}