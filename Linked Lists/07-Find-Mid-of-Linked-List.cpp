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

Node *mergeTwoLinkedList(Node *head1, Node *head2)
{
    Node *FinalHead = NULL;
    Node *FinalTail = NULL;

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data)
    {
        FinalHead = head1;
        FinalTail = head1;
        head1 = head1->next;
    }
    else
    {
        FinalHead = head2;
        FinalTail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            FinalTail->next = head1;
            head1 = head1->next;
        }
        else
        {
            FinalTail->next = head2;
            head2 = head2->next;
        }
        FinalTail = FinalTail->next; // Move FinalTail to the last added node
    }

    // Update FinalTail if either head1 or head2 has remaining elements
    if (head1 != NULL)
    {
        FinalTail->next = head1;
    }
    else if (head2 != NULL)
    {
        FinalTail->next = head2;
    }

    return FinalHead;
}


int main()
{
    Node *head1 = inputList();
    Node *head2 = inputList();

    printList(head1);
    cout << endl;
    printList(head2);
    cout << endl;
    Node *ans = mergeTwoLinkedList(head1, head2);
    printList(ans);
}