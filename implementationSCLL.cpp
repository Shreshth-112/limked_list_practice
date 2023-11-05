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

void printSCLL(Node *head){
    Node *temp = head;
    if(head == NULL) return;
    while(head->next != temp){
        cout << head->data << " ";
        head = head->next; 
    }
    cout << head->data;
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    // Node *head = NULL;
    printSCLL(head);

    return 0;
}