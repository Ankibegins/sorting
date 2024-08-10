#include <iostream>
using namespace std;

int main()
{
    int a[10] = {1, 2, 2, 3, 4, 5, 5, 5, 6, 6};
    int i, j;
    int dup = 0;
    for (i = 0; i < 9; i++)
    {
        if (a[i] == a[i + 1])
        {
            for (j = i; a[i] == a[j]; j++)
                ;
            cout << "no. of dup" << j - i;
            i = j - 1;
        }
    }

    return 0;
}