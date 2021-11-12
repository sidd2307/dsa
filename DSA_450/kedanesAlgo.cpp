#include <iostream>
#include <limits.h>
using namespace std;

int kedanesAlgo(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    cout << "Kedanes Algorithm: " << endl;
    int arr[5] = {1, 2, 3, -2, 5};

    int res = kedanesAlgo(arr, 5);

    cout << "Max Sum is: " << res << endl;

    return 0;
}
