#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsize){
    int result=nums[0];
    for (int i = 1; i < numsize; i++)
    {
        result ^= nums[i];
    }
    return result;
}

int main(){
    int nums1[3]={2,2,1};
    int nums2[5]={4,1,2,1,2};
    int nums3[1]={1};
    int ans1=singleNumber(nums1, 3);
    int ans2=singleNumber(nums2, 5);
    int ans3=singleNumber(nums3, 1);
    printf("%d\n", ans1);
    printf("%d\n", ans2);
    printf("%d\n", ans3);

    return 0;
}