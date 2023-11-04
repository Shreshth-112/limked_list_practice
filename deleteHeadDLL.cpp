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

Node *deleteHead(Node *head)
{
    Node *curr = head;
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        curr = head->next;
        delete head;
        return curr;
    }
}
int main()
{
    // Node *head = NULL;
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    head->next = temp;
    temp->next = temp1;
    temp1->prev = temp;
    temp->prev = head;

    printDLL(head);

    head = deleteHead(head);

    printDLL(head);

    return 0;
}