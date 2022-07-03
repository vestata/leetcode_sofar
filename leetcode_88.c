#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
return *(int *)a - *(int *)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    
    
}

void printArray(int *arr, int arrsize){
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int nums1[]={1,2,3,0,0,0};
    int nums2[]={2,5,6};
    qsort(nums1, 6, sizeof(int), cmp);
    printArray(nums1, 6);

    return 0;
}