/* TREE REPRESENTATION */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    print(root->left);
    print(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);

    print(root);
}