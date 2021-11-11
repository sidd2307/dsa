#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[], int n)
{
    int start = 0;
    int mid = 0;
    int end = n - 1;

    while (mid <= end)
    {
        if (a[mid] == 0)
        {
            swap(&a[start++], &a[mid++]);
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&a[end--], &a[mid]);
        }
    }
}

int main()
{

    int n = 5;
    int a[5] = {0, 2, 1, 2, 0};

    sort012(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
