#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int brr[h - l + 1]; // Corrected size of auxiliary array
                        // Merging the two halves into the auxiliary array
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
            brr[k++] = arr[i++];
        else
            brr[k++] = arr[j++];
    }

    // Copy remaining elements from the left half
    while (i <= mid)
        brr[k++] = arr[i++];

    // Copy remaining elements from the right half
    while (j <= h)
        brr[k++] = arr[j++];

    // Copy merged elements back to the original array
    for (i = l, k = 0; i <= h; i++, k++)
    {
        arr[i] = brr[k];
    }
}

void merge_sort(int arr[], int n)
{
    int p, i, l, h, mid;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(arr, l, mid, h);
        }
    }

    if (p / 2 < n)
    {
        merge(arr, 0, p / 2 - 1, n - 1);
    }
}

int main()
{
    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    { // Corrected the loop condition
        cin >> a[i];
    }

    merge_sort(a, n);

    // Optional: Print sorted array to verify correctness
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
