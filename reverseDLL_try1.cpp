#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = next = NULL;
    }
};

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse(Node *head)
{
    while (head->next != NULL)
        head = head->next;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->prev;
    }
}

int main()
{

    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp;
    temp->next = temp2;
    temp2->prev = temp;
    temp->prev = head;

    printDLL(head);

    reverse(head);

    return 0;
}