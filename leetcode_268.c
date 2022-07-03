#include <stdio.h>

int missingNumber(int* nums, int numsSize){
    int total=(numsSize)*(numsSize+1)/2;
    int sum=0;
    for (int i = 0; i < numsSize; i++)
    {
        sum = sum+nums[i];
    }
    return (total-sum);
}

int main(){
    int nums1[]={3,0,1};
    int nums2[]={0,1};
    int nums3[]={9,6,4,2,3,5,7,0,1};
    int nums4[]={1,2};
    
    printf("%d\n", missingNumber(nums1, 3));
    printf("%d\n", missingNumber(nums2, 2));
    printf("%d\n", missingNumber(nums3, 9));
    printf("%d\n", missingNumber(nums4, 2));
    return 0;
}