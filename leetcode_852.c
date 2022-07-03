#include <stdio.h>

int peakIndexInMountainArray(int* arr, int arrSize){
    int low=0;
    int high=arrSize-1;
    int mid=0;
    
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }else{
            high=mid;
        }
        if(low==high) break;
    }

    return high;
}

int main(){
    int num1[]={0, 1, 0};
    int num2[]={0,2,1,0};
    int num3[]={0,10,5,2};
    int num4[]={0,4,5,6,8,10,7,3,0};
    //printf("%d\n", num1[2]);
    //printf("%d\n", num2[2]);
    
    printf("%d\n", peakIndexInMountainArray(num1, 3));
    printf("%d\n", peakIndexInMountainArray(num2, 4));
    printf("%d\n", peakIndexInMountainArray(num3, 4));
    printf("%d\n", peakIndexInMountainArray(num4, 9));
    
    return 0;
}