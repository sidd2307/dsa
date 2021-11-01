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

node *merge2SortedLL(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummyNode = new node(-1);
    node *ptr3 = dummyNode;

    while (ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while (ptr2)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
}

int main()
{
    node *head1 = new node(1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);

    node *head2 = new node(2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);

    cout << "LL 1: " << endl;
    display(head1);

    cout << "LL 2: " << endl;
    display(head2);

    node *head3 = merge2SortedLL(head1, head2);
    cout << "Merge 2 sorted Linked List" << endl;
    display(head3);

    return 0;
}

// Result:
// LL 1:
// 1 4 5 7
// LL 2:
// 2 3 6
// Merge 2 sorted Linked List
// 1 2 3 4 5 6 7
