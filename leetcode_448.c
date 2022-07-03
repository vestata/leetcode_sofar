#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* count=malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i]-1]++;
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
    int nums1[]={4,3,2,7,8,2,3,1};
    //int n = sizeof(nums1)/sizeof(nums1[0]);
    printarray(nums1, sizeof(nums1)/sizeof(nums1[0]));

    int count[sizeof(nums1)/sizeof(nums1[0])]={0};
    for (int i = 0; i < sizeof(nums1)/sizeof(nums1[0]); i++)
    {
        count[nums1[i]-1]++;
    }
    printarray(count, sizeof(nums1)/sizeof(nums1[0]));
    for (int j = 0; j < 8; j++)
    {
        if(count[j]==0) printf(" %d\t", j+1);
    }
    printf("\n");
    
    
    
    return 0;
}