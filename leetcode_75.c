#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortColors(int* nums, int numsSize){
    for (int i = 0; i < numsSize-1; i++)
    {
        for (int j = 0; j < numsSize-i-1; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(&nums[j], &nums[j + 1]);
        }
    }
}

void printArray(int* arr)
{
    int i;
    int n=sizeof(arr);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int num1[]={2,0,2,1,1,0};
    int num2[]={2,0,1};
    sortColors(num1, sizeof(num1)/sizeof(num1[0]));
    printArray(num1);
    
    return 0;
}