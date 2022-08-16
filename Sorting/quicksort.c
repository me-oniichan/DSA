#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int j = start-1;
    for(int i = start; i < end; i++){
        if (arr[i] < arr[end]){
            j++;
            swap(arr+j, arr+i);
        }
    }
    swap(arr+j+1, arr+end);
    return j+1;
};

void quicksort(int arr[], int start, int end){
    if (end <= start) return;
    int q = partition(arr, start, end);
    quicksort(arr, start, q-1);
    quicksort(arr, q+1, end);
};

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i =0; i < n; i++) scanf("%d", arr+i);

    quicksort(arr, 0, n-1);

    for(int i=0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}