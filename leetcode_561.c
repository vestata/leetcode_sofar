#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


int arrayPairSum(int* nums, int numsSize){
    quickSort(nums, 0, numsSize-1);
    int sum=0;
    int i=0;
    int *ptr=nums;
    while (i < numsSize)
    {
        sum = sum + *(ptr+i);
        i=i+2;
    }
    return sum;
}


int main(){
    int nums1[]={1, 4, 2, 3};
    int nums2[]={6,2,6,5,1,2};
    //bubbleSort(nums1, 4);
    //bubbleSort(nums2, 6);
    printf("%d\n", arrayPairSum(nums1, 4));
    printf("%d\n", arrayPairSum(nums2, 6));
    return 0;
}