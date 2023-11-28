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

Node *insertList()
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

Node *deleteNode(Node *head, int pos)
{

    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != NULL && cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        cout << "You have entered index out of list" << endl;
        return head;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
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
    Node *head = insertList();
    int pos;
    cin >> pos;
    Node *temp = deleteNode(head, pos);
    printList(temp);
}