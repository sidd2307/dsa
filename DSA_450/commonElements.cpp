#include <iostream>
using namespace std;

void commonElements(int a1[], int a2[], int a3[], int a, int b, int c)
{
    int i = 0, j = 0, k = 0;

    while (i < a && j < b && k < c)
    {
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout << a1[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else if (a1[i] > a3[k] && a2[j] > a3[k])
        {
            k++;
        }
        else{
            j++;
        }
    }

    cout << endl;
}

int main()
{
    cout << "Common Elements are: " << endl;
    int a1[6] = {1, 5, 10, 20, 40, 80};
    int a2[5] = {6, 7, 20, 80, 100};
    int a3[8] = {3, 4, 15, 20, 30, 70, 80, 120};

    commonElements(a1, a2, a3, 6, 5, 8);

    return 0;
}
