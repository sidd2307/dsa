#include <iostream>
using namespace std;

// An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that all negative numbers appear before all positive numbers.

// Two-Pointer approach

// Check If the left and right pointer elements are negative then simply increment the left pointer.
// Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
// Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
// Repeat the above 3 steps until the left pointer ≤ right pointer.

void shiftall(int arr[], int left, int right)
{
    while (left <= right)
    {
        if ((arr[left] < 0) && (arr[right] < 0))
        {
            left++;
        }
        else if ((arr[left] > 0) && (arr[right] < 0))
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else if ((arr[left] > 0) && (arr[right] > 0))
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }
}

void display(int arr[], int right)
{
    for (int i = 0; i <= right; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    shiftall(arr, 0, arr_size - 1);
    display(arr, arr_size - 1);
    return 0;
}
