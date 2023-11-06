#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
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

Node *delHead(Node *head, int k)
{
    Node *curr = head;
    for (int i = 1; i < k; i++)
    {
        head = head->next;
    }
    cout << head->data << endl;

    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return curr;
}

int main()
{
    Node *head = new Node(10);
    // head -> next = head;
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    int k = 3;
    printlist(head);
    head = delHead(head, k);
    printlist(head);
    return 0;
}