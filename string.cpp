#include <iostream>
using namespace std;
int main()
{
    char a[] = "hello";
    char b[] = "hellbe";
    int j, i;
    for (i = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
    {
        cout << "equal";
    }
    else if (a[i] < b[j])
        cout << "samll";
    else
        cout << "greater";

    return 0;
}