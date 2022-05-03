#include <stdio.h>

void insertionSort(int *arr, int size){
    for (int i = 1; i < size; i++){
        for(int j = i; j > 0; j--){
            if (arr[j-1] > arr[j]){
                arr[j-1] = arr[j] + arr[j-1];
                arr[j] = arr[j-1] - arr[j];
                arr[j-1] = arr[j-1] - arr[j];
            }
        }
    }
}

int main(){
    int arr[] = {43,23,4,5,3,4,65,4}, size = 8;
    insertionSort(&arr[0], size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}