/* Inorder Traversal
    TC : O(n)
    SC : O(n)
*/

#include <iostream>
#include "Tree.cpp"
using namespace std;

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    root->right->left = new Node(7);

    inorder(root);
}