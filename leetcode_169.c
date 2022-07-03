#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int major;
    int count=0;
    for (int i = 0; i < numsSize; i++)
    {
        if (count==0)
        {
            major=nums[i];
            count++;
        }
        else{
            if (major==nums[i])
            {
                count++;
            }
            else{
                count--;
            }
        }
    }
    return major;
}

int main(){
    int nums1[]={3,2,3};
    int nums2[]={2,2,1,1,1,2,2};

    printf("%d\n", majorityElement(nums1, 3));
}