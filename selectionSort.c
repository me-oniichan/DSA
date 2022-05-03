#include <stdio.h>

void quickSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = arr[i], min_idx = i;
        for (int j = i; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                min_idx = j;
            }
        }
        if (i != min_idx)
        {
            arr[i] = arr[i] + arr[min_idx];
            arr[min_idx] = arr[i] - arr[min_idx];
            arr[i] = arr[i] - arr[min_idx];
        }
    }
}

int main()
{
    int arr[] = {43, 23, 4, 5, 3, 4, 65, 4}, size = 8;
    quickSort(&arr[0], size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}