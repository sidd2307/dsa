#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (!head)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int length(node *head)
{
    node *temp = head;
    int l = 0;

    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *appendKNodesAtStart(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *temp = head;

    int l = length(head);
    int count = 1;

    while (temp->next)
    {
        if (count == l - k)
        {
            newTail = temp;
        }
        if (count == l - k + 1)
        {
            newHead = temp;
        }
        count++;
        temp = temp->next;
    }

    newTail->next = NULL;
    temp->next = head;
    return newHead;
}

void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Append K Nodes at start of LL" << endl;
    node *LL = new node(1);
    insertAtTail(LL, 2);
    insertAtTail(LL, 3);
    insertAtTail(LL, 4);
    insertAtTail(LL, 5);
    insertAtTail(LL, 6);

    cout << "Initial LL: " << endl;
    display(LL);

    node *newHead = appendKNodesAtStart(LL, 3);
    cout << "Updated LL: " << endl;
    display(newHead);

    return 0;
}

// Result:
// Append K Nodes at start of LL
// Initial LL: 
// 1 2 3 4 5 6
// Updated LL:
// 4 5 6 1 2 3
