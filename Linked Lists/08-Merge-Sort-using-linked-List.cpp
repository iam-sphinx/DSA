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
    int val;
    cin >> val;
    Node *Head = NULL;
    Node *Tail = NULL;
    while (val != -1)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
        cin >> val;
    }
    return Head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *mergeSort(Node *head)
{
    
}

int main()
{
    Node *input = inputList();

    cout << endl;

    Node *output = mergeSort(input);
    printList(output);
    cout << endl;
}