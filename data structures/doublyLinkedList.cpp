#include <iostream>
using namespace std;

// node class declaration ----------------------------------------------------------------------------------------------
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// insertion at head ----------------------------------------------------------------------------------------------------
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head)
    {
        head->prev = n;
    }
    head = n;
}

// insert at Tail -------------------------------------------------------------------------------------------------------
void insertAtTail(node *&head, int val)
{
    if (!head)
    {
        insertAtHead(head, val);
    }
    node *n = new node(val);
    node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// display all nodes ----------------------------------------------------------------------------------------------------
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

// delete from Head ----------------------------------------------------------------------------------------------------
void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;

    delete temp;
}

// delete from given position --------------------------------------------------------------------------------------------
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    int count = 1;
    node *temp = head;
    while (temp && (count != pos))
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if (temp->next)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// driver function -------------------------------------------------------------------------------------------------------
int main()
{
    cout << "Doubly Linked List Imlementation:" << endl;
    node *DLL = new node(1);
    insertAtHead(DLL, 2);
    insertAtHead(DLL, 3);
    insertAtHead(DLL, 4);
    insertAtHead(DLL, 5);
    insertAtTail(DLL, 6);
    insertAtTail(DLL, 7);

    cout << "DLL initial: "
         << " ";
    display(DLL);

    deleteAtHead(DLL);
    cout << "DLL after Delete At Head: "
         << " ";
    display(DLL);

    deletion(DLL, 3);
    cout << "DLL after deleting from pos 3: " << " ";
    display(DLL);

    return 0;
}

// Result ----------------------------------------------------------------------------------------------------
// Doubly Linked List Imlementation:
// DLL initial:  5 4 3 2 1 6 7 
// DLL after Delete At Head:  4 3 2 1 6 7    
// DLL after deleting from pos 3:  4 3 1 6 7 