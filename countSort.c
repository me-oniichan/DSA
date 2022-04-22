#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int size){
    int max_ = arr[0];
    for (int i= 0; i < size; i++){
        if (max_< arr[i]) max_ = arr[i];
    }

    return max_;
}

void countSort(int arr[], int size){
    int max_ = max(arr, size)+1;
    int *arr_dup = (int*)calloc(max_, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr_dup[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < max_; i++)
    {
        for (int j = 0; j < arr_dup[i]; j++)
        {
            arr[index] = i;
            index++;
        }
        
    }
}

int main(){
    int arr[] = {43,23,4,5,3,4,65,4}, size = 8;
    countSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}