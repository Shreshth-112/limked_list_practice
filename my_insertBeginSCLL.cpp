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

void printlist(Node *head)
{
    if (head == NULL)
        return;
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

Node *insertBegin(Node *head, int x)
{
    Node *curr = head;
    Node *temp = new Node(x);
    temp->next = head;
    while (head->next != curr)
        head = head->next;
    head->next = temp;
    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    printlist(head);
    int x = 2;
    head = insertBegin(head, x);
    printlist(head);
    return 0;
}