#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  
  int pivot = array[high];
    //pivot設在最後一個array數
  int i = (low - 1);
    //i設為low前面一個，這裡low-1的原因是下一個for loop 為了要跑i++(統一性)所以這裡多減一個1
  for (int j = low; j < high; j++) {  //從前面開始scan 若是<=pivot, i++然後交換
    if (array[j] <= pivot) {

      i++;
      swap(&array[i], &array[j]);
    }
  }//記錄的兩個pointer互換，which i>pivot,而j<=pivot

  swap(&array[i + 1], &array[high]);
  //全部都走完之後跟pivot 換，將pivot換到中間的位置(i,j重點的位子)
  //(i+1) 被swap值之後的那個值

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}