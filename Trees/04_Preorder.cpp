/* PREORDER TRAVERSAL
    Time Cpx = O(n)
    Spc Cpx = O(n)
*/

#include <iostream>
#include "Tree.cpp"

using namespace std;
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node * root = new Node(4);
    root -> left = new Node (5);
    root -> right = new Node(6);
    root -> right -> left = new Node(7);

    preorder(root);
}