#include <stdio.h>

void bubbleSort(int *arr, int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-1-i; j++){
            if (arr[j+1] < arr[j]){
                arr[j+1] = arr[j] + arr[j+1];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] = arr[j+1] - arr[j];
            }
            
        }
    }
}

int main(){
    int arr[] = {43,23,4,5,3,4,65,4}, size = 8;
    bubbleSort(&arr[0], size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}