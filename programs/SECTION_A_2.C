#include<stdio.h>
#include<limits.h>

int findMaxIntArray(int arr[],int len_arr)
{
    int max;
    for(int i=0;i<len_arr;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}


int countItemsArray(int countItemsArr[],int actualArr[], int len_act_arr )
{
    int len_count_arr = findMaxIntArray(actualArr,len_act_arr);
    for(int i=0;i<len_act_arr;i++)
    {
        countItemsArr[actualArr[i]]= countItemsArr[actualArr[i]] + 1;
    }
}

int modifyCountArr(int countItemsArr[],int actual_arr[], int len_act_arr)
{
    int len_count_arr = findMaxIntArray(actual_arr,len_act_arr);
    for(int i=1;i<len_count_arr;i++)
    {
        countItemsArr[i]= countItemsArr[i-1] + countItemsArr[i];
    }
}