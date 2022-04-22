#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int size1 = mid-left+1;
    int size2 = right-mid;

    int arr1[size1]; int arr2[size2];
    
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[left+i];
    }
    
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid+1+i];
    }    
    
    int mergeIndex = left, arr1_index = 0, arr2_index = 0;

    while (arr1_index < size1 && arr2_index < size2)
    {
        if( arr1[arr1_index] > arr2[arr2_index]){
            arr[mergeIndex] = arr2[arr2_index];
            arr2_index++;
        }
        else{
            arr[mergeIndex] = arr1[arr1_index];
            arr1_index++;
        }
        mergeIndex++;
    }

    while (arr1_index < size1)
    {
        arr[mergeIndex] = arr1[arr1_index];
        arr1_index++; mergeIndex++;
    }

    while (arr2_index < size2)
    {
        arr[mergeIndex] = arr2[arr2_index];
        arr2_index++; mergeIndex++;
    }
}

void mergeSort(int arr[], int low, int high){
    if (low >= high) return;

    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid,high);
}

int main(){
    int arr[] = {43,23,4,5,3,4,65,4}, size = 8;
    mergeSort(arr, 0, size-1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}