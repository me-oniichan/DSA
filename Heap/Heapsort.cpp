#include <iostream>
using namespace std;

void heapify(int arr[], int n, int m){
    //to maintain heap structure
    while (m < n/2){
        int l = m;
        if (arr[l] > arr[2*l+1]) l = 2*m+1;
        if (2*m+2 < n && arr[l] > arr[2*m+2]) l = 2*m+2;

        if(m == l) break;
        swap(arr[m], arr[l]);
        m = l;
    }
} 

void maxHeapify(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int idx = i;
        while (idx < n / 2)
        {
            int l = idx;
            if (arr[idx] < arr[2 * idx + 1])
                l = 2 * idx + 1;
            if (2 * idx + 2 < n && arr[l] < arr[2 * idx + 2])
                l = 2 * idx + 2;
            swap(arr[idx], arr[l]);
            if (idx == l)
                break;
            idx = l;
        }
    }
} 

void heapsort(int arr[], int n){
    maxHeapify(arr, n);
    for (int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, n, 0);
    }
    return;
}

int main(){
    // size of array
    int n;
    cin >> n;
    int arr[n];
    // take array input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapsort(arr, n);
    for(int i: arr) cout<<i<<' ';

return 0;
}