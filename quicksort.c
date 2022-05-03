#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int k = high;
    for (int i = high; i > low; i--)
    {
        if (arr[i] > pivot){
            arr[i] += arr[k];
            arr[k] = arr[i] - arr[k];
            arr[i] = arr[i] - arr[k];
            k--;
        }
    }
    arr[k] += pivot;
    arr[low] = arr[k] - pivot;
    arr[k] = arr[k] - arr[low];
    return k;
}

void quickSort(int arr[], int high, int low){
    if (low < high){
        int index = partition(arr, low, high);
        quickSort(arr, index-1, low);
        quickSort(arr, high, index+1);
    }
}

int main(){
    int arr[] = {43,23,4,5,3,4,65,4}, size = 8;
    quickSort(&arr[0], size-1, 0);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}