#include <iostream>
using namespace std;

int countInversions(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; i < n; i++)
        {
            if (arr[j] > arr[i])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cout << "Count Inversions: " << endl;
    int arr[5] = {2, 4, 1, 3, 5};

    cout << countInversions(arr, 5) << endl;

    return 0;
}
