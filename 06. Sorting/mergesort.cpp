#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s+(e-s) / 2;
    int len1 = mid-s+1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainArrayindex = s;

    while (leftindex < len1 && rightindex < len2)
    {
        if (left[leftindex] < right[rightindex])
        {
            arr[mainArrayindex++] = left[leftindex++];
        }
        else
        {
            arr[mainArrayindex++] = right[rightindex++];
        }
    }

    while (leftindex < len1)
    {
        arr[mainArrayindex++] = left[leftindex++];
    }


    while (rightindex < len2)
    {
        arr[mainArrayindex++] = right[rightindex++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    int arr[] = {5, 4,13,2,12};
    int size = 5;
    int s = 0;
    int e = size - 1;
    mergeSort(arr, s, e);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}