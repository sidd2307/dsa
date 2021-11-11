#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
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
    int a[5] = {1, 2, 3, 4, 5};
    cout << "Initial Array: " << endl;
    display(a, 5);

    rotate(a, 5);

    cout << "Rotated Array: " << endl;
    display(a, 5);
}
