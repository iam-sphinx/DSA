#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *input()
{
    int val;
    cin >> val;
    Node *head = NULL;
    Node *tail = NULL;
    while (val != -1)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> val;
    }
    return head;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

Node *insertNode(int val, int pos, Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos - 1 == 0)
    {
        Node *newNode = new Node(val);
        newNode->next = head->next;
        head = newNode;
        return head;
    }
    head -> next = insertNode(val, pos - 1, head -> next);
    return head;
}

int main()
{
    Node * head = input();
    printList(head);
    int val, pos;
    cin>>val, pos;
    head = insertNode(val, pos, head);
    printList(head);
}