#include <iostream>
using namespace std;

#define N 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[N];
        top = -1;
    }

    void push(int x)
    {
        if (top == N - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    cout << "Stack Imlementation" << endl;
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top: " << endl;
    int top = st.Top();
    cout << top << endl;

    cout << "Popping 2 items" << endl;
    st.pop();
    st.pop();

    cout << "Top after popping: " << endl;
    int top2 = st.Top();
    cout << top2 << endl;

    return 0;
}

// Output
// Stack Imlementation
// Top: 
// 4
// Popping 2 items    
// Top after popping:
// 2