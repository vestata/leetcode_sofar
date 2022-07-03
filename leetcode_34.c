#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans=(int *)malloc(sizeof(int)*2);
    ans[0]=-1;
    ans[1]=-1;
    if(numsSize==0) return ans;
    int low=0;
    int high=numsSize-1;
    int mid=0;
    while(low<=high){
        mid=low+(high-low)/2;
        if(nums[mid]<target){
            low=mid+1;
        }else{
            high=mid;
        }
        if(low==high) break;
    }
    if(nums[high]!=target) return ans;
    ans[0]=low;
    ans[1]=high;
    if(numsSize==1) return ans;
    while(low>0){
        if(nums[low-1]==target){
            low-=1;
            ans[0]=low;
        }else{
            break;
        }
    }
    while(high<(numsSize-1)){
        if(nums[high+1]==target){
            high+=1;
            ans[1]=high;
        }else{
            break;
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
    int num1[]={5,7,7,8,8,10};
    int num2[]={};
    printArray(searchRange(num1, 6, 8, 2),2);
    printArray(searchRange(num1, 6, 6, 2),2);
    printArray(searchRange(num2, 0, 0, 2),2);
    return 0;
}