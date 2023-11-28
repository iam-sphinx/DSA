#include <bits/stdc++.h>
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

int main()
{
    Node *head = inputList();
    int counter;
    cin >> counter;
    Node *temp = head;
    while (temp != NULL && counter >= 2)
    {
        temp = temp->next;
        counter--;
    }
    if (temp == NULL)
    {
        cout << "Index out of bound" << endl;
    }
    cout << temp->data << endl;
    return 0;
}