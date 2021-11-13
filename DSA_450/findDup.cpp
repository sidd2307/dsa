#include <iostream>
#include <algorithm>
using namespace std;

void findDup(int arr[], int n)
{
    cout << "This method modifies array" << endl;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i] << endl;
        }
    }
}

// For example, if the input array is [1, 3, 3, 2][1,3,3,2], then for 11,
// flip the number at index 11, making the array [1,-3,3,2][1,−3,3,2].
// Next, for -3−3 flip the number at index 33, making the array [1,-3,3,-2][1,−3,3,−2].
//  Finally, when we reach the second 33, we'll notice that nums[3]nums[3] is already negative,
//  indicating that 33 has been seen before and hence is the duplicate number.

void findDupNegate(int arr[], int n)
{
    cout << "This method temporarily modifies the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            arr[arr[i]] = -arr[arr[i]];
        }
        else
        {
            cout << abs(arr[i]) << endl;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = abs(arr[i]);
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
    cout << "Finding Duplicate in an array: " << endl;

    int arr1[5] = {1, 3, 4, 2, 2};
    findDup(arr1, 5);
    display(arr1, 5);

    int arr2[5] = {1, 3, 4, 2, 2};
    findDupNegate(arr2, 5);
    display(arr2, 5);

    return 0;
}
