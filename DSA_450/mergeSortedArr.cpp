#include <iostream>
using namespace std;

void mergeSorted1(int a1[], int a2[], int m, int n)
{
    cout << "No use of extra space" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        int last = a1[m - 1];
        int j;

        for (j = m - 2; j >= 0 && a1[j] > a2[i]; j--)
        {
            a1[j + 1] = a1[j];
        }

        if (j != m - 2 || last > a2[i])
        {
            a1[j + 1] = a2[i];
            a2[i] = last;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Merge two Sorted Arrays" << endl;
    int a1[6] = {1, 5, 9, 10, 15, 20};
    int a2[4] = {2, 3, 8, 13};

    mergeSorted1(a1, a2, 6, 4);
    cout << "Array 1: " << endl;
    display(a1, 6);
    cout << "Array 2: " << endl;
    display(a2, 4);

    return 0;
}
