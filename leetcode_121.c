#include <stdio.h>
/*
int maxProfit(int* prices, int pricesSize){
    int count=0;
    int max=0;
    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i; j < pricesSize; j++)
        {
            if(prices[j]>prices[i]){
                count=prices[j]-prices[i];
                if(count>max)
                    max=count;
            }
        }
    }
    return max;
}
*/
//Time Limit Exceeded   199 / 211 test cases passed.
// 大概O(n^2) 要花太久了

int maxProfit(int* prices, int pricesSize){
    if(pricesSize<=0)
        return 0;
    int price=prices[0];
    int profit=0;
    for (int i = 1; i < pricesSize; i++)
    {
        if(prices[i]<price)
            price=prices[i];
        if(profit<prices[i]-price)
            profit=prices[i]-price;
    }
    return profit;
}

int main(){
    int nums1[]={7,1,5,3,6,4};
    int nums2[]={7,6,4,3,1};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    int size2 = sizeof(nums2)/sizeof(nums2[0]);

    printf("%d\n", maxProfit(nums1, size1));
    return 0;
}