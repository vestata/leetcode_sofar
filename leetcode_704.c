#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid=(left+right)/2;
    while(left<=right){
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
        mid=(left+right)/2;
    }
    return -1;
}

int main(){
    int nums1[] = {-1,0,3,5,9,12};
    printf("%d\n", search(nums1, 6, 9));

    return 0;
}