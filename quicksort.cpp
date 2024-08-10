#include <iostream>
#include <stdlib.h>
#include <math.h>
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
using namespace std;
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[l], arr[j]);
    return j;
}
void quicsort(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quicsort(arr, l, j - 1);
        quicsort(arr, j + 1, h);
    }
}

int main()
{
    int a[] = {11, 43, 23, 67, 34, 23, 67, 23, 23, 67}, n = 10;
    quicsort(a, 0, n);

    for (int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}