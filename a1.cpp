#include <iostream>
using namespace std;

class ar
{
    int *a;
    int l, s;

public:
    ar()
    {
        a = new int[10];
        l = 0;
        s = 10;
    }
    ar(int sz)
    {
        s = sz;
        l = 0;
        a = new int[s];
    }
    ~ar()
    {
        delete[] a;
    }
    void display();
    void insert(int n);
    void displayar(int *p, int ml);
    int *merge(struct ar *brr, int &ml);
    int *union1(struct ar *brr, int &ml);
    int *intersection(struct ar *brr, int &ml);
    int *sub(struct ar *brr, int &ml);
};

void ar::display()
{
    for (int i = 0; i < l; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void ar::insert(int n)
{
    int i;
    if (l < s)
    {
        for (i = l - 1; i >= 0 && n < a[i]; i--)
        {
            a[i + 1] = a[i];
        }
        a[i + 1] = n;
        l++;
    }
}

int *ar::merge(struct ar *brr, int &ml)
{
    int *p = new int[l + brr->l];
    int i = 0, j = 0, k = 0;

    while (i < l && j < brr->l)
    {
        if (a[i] <= brr->a[j])
        {
            p[k++] = a[i++];
        }
        else
        {
            p[k++] = brr->a[j++];
        }
    }

    while (i < l)
    {
        p[k++] = a[i++];
    }

    while (j < brr->l)
    {
        p[k++] = brr->a[j++];
    }

    ml = k;
    return p;
}

void displayar(int *p, int ml)
{
    for (int i = 0; i < ml; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
int *ar::union1(struct ar *brr, int &ml)
{
    int *p = new int[l + brr->l];
    int i = 0, j = 0, k = 0;

    while (i < l && j < brr->l)
    {
        if (a[i] < brr->a[j])
        {
            p[k++] = a[i++];
        }
        else if (a[i] == brr->a[j])
        {
            p[k++] = a[i++];
            j++;
        }
        else

        {
            p[k++] = brr->a[j++];
        }
    }

    while (i < l)
    {
        p[k++] = a[i++];
    }

    while (j < brr->l)
    {
        p[k++] = brr->a[j++];
    }

    ml = k;
    return p;
}
int *ar::intersection(struct ar *brr, int &ml)
{
    int *p = new int[l + brr->l];
    int i = 0, j = 0, k = 0;

    while (i < l && j < brr->l)
    {
        if (a[i] < brr->a[j])
        {
            i++;
        }
        else if (a[i] == brr->a[j])
        {
            p[k++] = a[i++];
            j++;
        }
        else

        {
            j++;
        }
    }

    ml = k;
    return p;
}
int *ar::sub(struct ar *brr, int &ml)
{
    int *p = new int[l + brr->l];
    int i = 0, j = 0, k = 0;

    while (i < l && j < brr->l)
    {
        if (a[i] < brr->a[j])
        {
            p[k++] = a[i++];
        }
        else if (a[i] == brr->a[j])
        {
            i++;
            j++;
        }
        else

        {
            p[k++] = brr->a[j++];
        }
    }

    while (i < l)
    {
        p[k++] = a[i++];
    }

    while (j < brr->l)
    {
        p[k++] = brr->a[j++];
    }

    ml = k;
    return p;
}
int main()
{
    class ar x(10), *y;
    int input = 5;
    for (int n = 0; n < input; n++)
    {
        x.insert(9);
    }
    x.display();

    return 0;
}
