/* this is basic program to generate node for liked lists */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    /* this is constructor */
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int n;
    Node *head = NULL;
    while (n != -1)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = newNode;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cin >> n;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    // static creation of node
    Node n1(1); // this will create a node with data = 1 and next = NULL

    Node n2(2);

    Node n3(3);
    // saving head of linked list
    Node *head = &n1;

    // now connecting these two nodes
    n1.next = &n2;
    n2.next = &n3;

    print(head);

    Node *node = takeInput();
    print(node);
}