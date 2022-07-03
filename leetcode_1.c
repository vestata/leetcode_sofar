#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //*returnSize=2;
    int *ans=(int *)malloc(sizeof(int)*2);
    int temp;
    for (int i = 0; i < numsSize; i++)
    {
        temp=target-nums[i];
        for (int j = i+1; j < numsSize; j++)
        {
            if(nums[j]==temp){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }    
        }
    }
    return ans;
}

void printArray(int *arr, int arrsize){
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int num1[]={2,7,11,15};
    int num2[]={3,2,4};
    int num3[]={3,3};
    printArray(num1, 4);
    printArray(twoSum(num1, 4, 9, 2), 2);
    printArray(twoSum(num2, 3, 6, 2), 2);
    return 0;
}