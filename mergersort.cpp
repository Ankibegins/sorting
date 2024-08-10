#include <iostream>
using namespace std;
void merge(int arr[], int l, int h, int mid)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int brr[h];
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
            brr[k++] = arr[i];
        else
            brr[k++] = arr[j];
    }
    for (; i <= mid; i++)
        brr[k++] = arr[i];
    for (; j <= h; j++)
        brr[k++] = arr[j];
    for (i = l; i <= h; i++)
    {
        arr[i] = brr[i];
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
        merge(arr, 0, p / 2, n - 1);
}
int main()
{
    int n, i;
    cout << "enter no. of elements";
    cin >> n;
    int a[n];
    cout << "enter the elements";
    for (i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, n);
    return 0;
    for (i = 0; i <= n; i++)
    {
        cout << a[i];
    }
}