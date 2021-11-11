#include <iostream>
#include <set>
#include <iterator>
#include <map>
using namespace std;

// Set is a data structure that allows only the distinct elements in it --> Union
// Time Complexity: O(m * log(m) + n * log(n))
void unionBySet(int a[], int b[], int x, int y)
{
    set<int> unionSet;

    for (int i = 0; i < x; i++)
    {
        unionSet.insert(a[i]);
    }

    for (int j = 0; j < y; j++)
    {
        unionSet.insert(b[j]);
    }

    for (auto itr = unionSet.begin(); itr != unionSet.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

// map stores distinct keys only
// Time Complexity: O(m+n)
void unionByMap(int a[], int b[], int x, int y)
{
    map<int, int> unionMap;

    for (int i = 0; i < x; i++)
    {
        unionMap.insert({a[i], i});
    }

    for (int j = 0; j < y; j++)
    {
        unionMap.insert({b[j], j});
    }

    for (auto itr = unionMap.begin(); itr != unionMap.end(); itr++)
    {
        cout << itr->first << " ";
    }
    cout << endl;
}

// Time Complexity: O(m+n)
void intersectionByHash(int a[], int b[], int x, int y)
{
    set<int> intersectionSet;

    for (int i = 0; i < x; i++)
    {
        intersectionSet.insert(a[i]);
    }

    for (int j = 0; j < y; j++)
    {
        if (intersectionSet.find(b[j]) != intersectionSet.end())
        {
            cout << b[j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int a[6] = {7, 1, 5, 2, 3, 6};
    int b[5] = {3, 8, 6, 20, 7};

    cout << "Get Union using Set: " << endl;
    unionBySet(a, b, 6, 5);

    cout << "Get Union using Map: " << endl;
    unionByMap(a, b, 6, 5);

    cout << "Get Intersection using Set: " << endl;
    intersectionByHash(a, b, 6, 5);

    return 0;
}
