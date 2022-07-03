#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid=0;

    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    
    return left; 
}

int main(){
    int nums1[]={1,3,5,6};
    int nums1size=4;
    printf("%d\n", searchInsert(nums1, nums1size, 5));
    printf("%d\n", searchInsert(nums1, nums1size, 2));
    printf("%d\n", searchInsert(nums1, nums1size, 7));

    return 0;
}