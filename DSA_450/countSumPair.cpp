#include <iostream>
#include <unordered_map>
using namespace std;

// Given an array of integers, and a number ‘sum’, find the number of pairs of integers in the array whose sum is equal to ‘sum’.

int countPairsWithGivenSum(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }

    return count;
}

int countPairsWithGivenSumNaive(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Optimised Solution:  "
         << countPairsWithGivenSum(arr, n, sum) << endl;

    cout << "Naive Solution:  "
         << countPairsWithGivenSumNaive(arr, n, sum) << endl;

    return 0;
}
