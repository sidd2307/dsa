#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int length(Node *head)
{
    Node *temp = head;
    int l = 0;

    while (temp)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

int getIntersectionPoint(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    Node *ptr1;
    Node *ptr2;
    int d;

    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *newNode;

    Node *head1 = new Node();
    head1->data = 10;

    Node *head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout << "Find Intersection Point of 2 Linked List: " << endl;

    cout << "Linked List 1: " << endl;
    display(head1);

    cout << "Linked List 2: " << endl;
    display(head2);

    cout << "Intersection Point is: ";
    cout << getIntersectionPoint(head1, head2);

    return 0;
}
