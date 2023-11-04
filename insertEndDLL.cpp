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

Node *insertEndDLL(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;
    if (head == NULL)
        return temp;
    else
    {
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }
    return head;
}

int main()
{
    // Node *head = NULL;    
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp;
    temp->next = temp2;
    temp2->prev = temp;
    temp->prev = head;

    printDLL(head);
    int x = 40;
    head = insertEndDLL(head, x);
    printDLL(head);
    return 0;
}