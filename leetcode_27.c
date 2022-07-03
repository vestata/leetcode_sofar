#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int count=0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i]==val)
        {
            for (int j = i+1; j < numsSize; j++)
            {
                nums[i]=nums[j];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}

int main(){
    int nums1[]={3,2,2,3};
    int nums2[]={0,1,2,2,3,0,4,2};

    printf("%d\n", removeElement(nums2, 8, 2));

    for (int i = 0; i < 8; i++)
    {
        printf("%d\t", nums1[i]);
    }
    
    

}