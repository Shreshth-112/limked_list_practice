#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *sortedInsert(Node *head, int d)
{
    Node *curr = head;
    Node *temp = new Node(d);
    while (curr->data < temp->data && curr->next != NULL)
    {
        curr = curr->next;
    }
    cout << curr->data << endl;

    if (curr->data < temp->data)
    {
        curr->next = temp;
        return head;
    }
    else
    {
        temp->next = curr->next;
        int to_swap = curr->data;
        curr->next = temp;
        curr->data = temp->data;
        temp->data = to_swap;
        return head;
    }
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    printLL(head);
    cout << endl;
    head = sortedInsert(head, 5);
    printLL(head);
    cout << endl;
    head = sortedInsert(head, 25);
    printLL(head);
    cout << endl;
    head = sortedInsert(head, 55);
    printLL(head);
    cout << endl;

    return 0;
}