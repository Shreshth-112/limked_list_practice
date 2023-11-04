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
    while (head != 0)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertBeginDLL(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    else
    {
        head->prev = temp;
        temp->next = head;
    }
    return temp;
}

int main()
{
    // Node *head = NULL;
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp;
    temp->prev = head;
    temp->next = temp2;
    temp2->prev = temp;

    printDLL(head);
    
    int x = 5;
    head = insertBeginDLL(head, x);

    printDLL(head);


    return 0;
}