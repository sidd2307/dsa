#include <iostream>
#include <limits.h>
using namespace std;

int maxProfit(int arr[], int n)
{
    int maxProfit = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int profit = arr[j] - arr[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

int maxProfitsOptimised(int arr[], int n)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minPrice)
        {
            minPrice = arr[i];
        }
        else if (arr[i] - minPrice > maxProfit)
        {
            maxProfit = arr[i] - minPrice;
        }
    }

    return maxProfit;
}

int main()
{
    cout << "Best Time to buy and sell stocks: " << endl;
    int arr[6] = {7, 1, 5, 3, 6, 4};

    int res1 = maxProfit(arr, 6);
    cout << "O(N*N) solution: " << res1 << endl;

    int res2 = maxProfitsOptimised(arr, 6);
    cout << "O(N) solution: " << res2 << endl;

    return 0;
}
