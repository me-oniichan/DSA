#include <iostream>
using namespace std;

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
};

void minHeapify(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int idx = i;
        while (idx < n / 2)
        {
            int l = idx;
            if (arr[idx] > arr[2 * idx + 1])
                l = 2 * idx + 1;
            if (2 * idx + 2 < n && arr[l] > arr[2 * idx + 2])
                l = 2 * idx + 2;
            swap(arr[idx], arr[l]);
            if (idx == l)
                break;
            idx = l;
        }
    }
};

int main()
{
    // size of array
    int n;
    cin >> n;
    int arr[n];
    // take array input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<"Max Heap"<<endl;
    maxHeapify(arr, n);
    for (auto i : arr)
        cout << i << ' ';

    minHeapify(arr, n);
    cout<<endl<<"Min Heap"<<endl;
    for (auto i : arr)
        cout << i << ' ';
    return 0;
}