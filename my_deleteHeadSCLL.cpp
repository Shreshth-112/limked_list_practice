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
    Node *temp = head;
    if (head == NULL)
        return;
    while (head->next != temp)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

Node *deleteHead(Node *head)
{
    Node *temp = head;
    while (head->next != temp)
    {
        head = head->next;
    }
    Node *curr = temp->next;
    head->next = temp->next;
    delete temp;
    return curr;
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head;

    printLL(head);
    head = deleteHead(head);
    printLL(head);

    return 0;
}