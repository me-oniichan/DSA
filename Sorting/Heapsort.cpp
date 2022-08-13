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

void minHeapify(int arr[], int n)
{
    //to build heap
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
};

void heapsort(int arr[], int n){
    minHeapify(arr, n);
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, n, 0);
    }
} 
 
int main(){
     // size of array
    int n;
    cin >> n;
    int arr[n];
    // take array input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    /**
     * @brief first build a heap, and then pick elements in sorted way while maintaining heap
     * time complexity to build heap : O(n)
     * time complexity to heapify : O(logn)
     * Time complexity to sort : O(nlogn)
     */

    heapsort(arr, n);

    for(auto i : arr) cout<<i<<' ';    
 
return 0;
}