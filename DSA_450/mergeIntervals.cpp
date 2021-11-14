#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    for (auto interval : arr)
    {
        if (res.empty() || res.back()[1] < interval[0])
        {
            res.push_back(interval);
        }
        else
        {
            res.back()[1] = max(res.back()[1], interval[0]);
        }
    }

    return res;
}

void display(vector<vector<int>> arr)
{
    int n = arr.size();

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << '[' << arr[i][0] << ", " << arr[i][1] << "]" << ',';
    }
    cout << "]";
    cout << endl;
}

int main()
{
    cout << "Merge overlapping intervals: " << endl;
    vector<vector<int>> arr;
    arr = {{1, 3},
           {2, 6},
           {8, 10},
           {15, 18}};
    vector<vector<int>> res = mergeIntervals(arr);

    display(res);

    return 0;
}
