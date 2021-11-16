#include <iostream>
#include <unordered_set>
using namespace std;

bool subarrayWithSum(int arr[], int n)
{
    unordered_set<int> sumSet;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum == 0 || (sumSet.find(currSum) != sumSet.end()))
        {
            return true;
        }

        sumSet.insert(currSum);
    }

    return false;
}

int main()
{
    int arr[] = {4, 2, - 3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subarrayWithSum(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
