#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int tmp;
    for(int i=0; i<numsSize; i++){
        if (nums[i]==0)
        {
            for (int j = i; j < numsSize; j++)
            {
                nums[j]=nums[j+1];
            }
        }
    }
}

int main(){
    int nums[]={0,1,0,3,12};
    int nums2[]={0};
    moveZeroes(nums, 5);
    moveZeroes(nums2, 1);
    for (int i = 0; i < 1; i++)
    {
        printf("%d\t", nums2[i]);
    }
    
    return 0;
}