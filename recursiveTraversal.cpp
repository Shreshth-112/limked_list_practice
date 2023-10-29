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

void rprintLL(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";

    rprintLL(head->next);
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    rprintLL(head);
    return 0;
}