#include <stdio.h>
#include <stdlib.h>
#include "quicksorth.h"

int heightChecker(int* heights, int heightsSize){
    int a[heightsSize];
    for (int i = 0; i < heightsSize; i++)
    {
        a[i]=heights[i];
    }
    
    quickSort(heights, 0, heightsSize);
    int count=0;
    for (int i = 0; i < heightsSize; i++)
    {
        if (a[i]!=heights[i])
        {
            count++;
        }
    }
    return count;
}

int main(){
    int heights[] = {1,1,4,2,1,3};
    /*quickSort(heights, 0, 5);
    int *ptr;
    ptr=heights;
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", *(ptr+i));
    }*/
    printf("%d\n", heightChecker(heights, 6));
    
    
    return 0;
}