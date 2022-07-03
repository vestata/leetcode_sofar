#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize){
    int i=0,j,sum=0;
    while(i<numsSize-sum)
    { if(nums[i]==0) 
         {for(j=i;j<numsSize-1-sum;j++)
             nums[j]=nums[j+1];            
             nums[numsSize-sum-1]=0;
             sum++;
             i=0; 
          }    
     else {i++;}
    }
}

int main(){
    int nums[]={0,1,0,3,12};
    int size=sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums, size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");
    
    return 0;
}