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
}

Node *insertAnyPosition(Node *head, int pos, int element)
{
    Node *temp = new Node(element);
    Node *curr = head;

    if (pos == 1)
    {
        temp -> next = head;
        return temp;
    }

    if (curr == NULL)
        return head;

    for (int i = 1; i <= pos - 2; i++)
    {
        curr = curr -> next;
    }
    temp -> next = curr -> next;
    curr -> next = temp;

    return head;
}

int main(){
    Node* head = new Node(10);
    head -> next = new Node(30);
    head -> next -> next = new Node(50);
    head -> next -> next -> next = new Node(70);
    head -> next -> next -> next -> next = new Node(90);

    printLL(head);
    cout << endl;

    int pos = 2;
    int element = 20;
    insertAnyPosition(head, pos, element);

    printLL(head);
    cout << endl;    

    return 0;
}