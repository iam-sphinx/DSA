/* postorder Traversal
    TC : O(n)
    SC : O(n)
*/

#include <iostream>
#include "Tree.cpp"
using namespace std;

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    root->right->left = new Node(7);

    postorder(root);
}