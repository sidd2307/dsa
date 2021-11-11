#include <iostream>
#include <limits.h>
using namespace std;

class minmax
{
public:
    int min;
    int max;

    minmax()
    {
        min = INT_MAX;
        max = INT_MIN;
    }
};

minmax minmaxArray(int arr[], int n)
{
    minmax res;

    if (n == 1)
    {
        res.min = arr[0];
        res.max = arr[0];
        return res;
    }

    if (arr[0] > arr[1])
    {
        res.min = arr[1];
        res.max = arr[0];
    }
    else
    {
        res.max = arr[1];
        res.min = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > res.max)
        {
            res.max = arr[i];
        }
        else if (arr[i] < res.min)
        {
            res.min = arr[i];
        }
    }
    return res;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;

    minmax res = minmaxArray(arr, arr_size);

    cout << "Minimum element is "
         << res.min << endl;
    cout << "Maximum element is "
         << res.max;

    return 0;
}
