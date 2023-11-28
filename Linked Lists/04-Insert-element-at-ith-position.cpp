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

Node *inputList()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    cin >> val;
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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *insertAtIdx(int val, int pos, Node *head)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    int count = 0;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp->next != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        temp->next = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main()
{
    Node *head = inputList();
    int val;
    int pos;
    cin >> val;
    cin >> pos;
    Node * head1 = insertAtIdx(val, pos, head);
    printList(head1);
}