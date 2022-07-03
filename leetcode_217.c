#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergesort.h"

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

_Bool containsDuplicate(int* nums, int numsSize){
    if(numsSize<=1) return false;
    mergeSort(nums, 0, numsSize-1);
    for (int i = 0; i < numsSize-1; i++)
    {
        if (nums[i]==nums[i+1])
        {
            return true;
        }
    }
    return false;
}

int main(){
    int nums1[]={1,2,3,1};
    int nums2[]={1,2,3,4};
    int nums3[]={1,1,1,3,3,4,3,2,4,2};

    
    printf("%d\n", containsDuplicate(nums1, 4));
    printf("%d\n", containsDuplicate(nums2, 4));
    printf("%d\n", containsDuplicate(nums3, 10));
    
    return 0;
}

/*
bool containsDuplicate(int* nums, int numsSize){
    int* count=(int *)malloc(sizeof(int)*numsSize);
    int cal=0;
    for (int i = 0; i < numsSize; i++)
    {
        
    }
    
}

int main(){
    int nums1[]={1,2,3,1};
    int nums2[]={1,2,3,4};
    int nums3[]={1,1,1,3,3,4,3,2,4,2};


    return 0;
}
*/