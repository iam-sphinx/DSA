/* PREORDER TRAVERSAL BY ITERATIVE WAY 
    TC -> O(N)
    SC -> O(H)
*/

#include <iostream>
#include <stack>
#include <vector>
#include "Tree.cpp"
using namespace std;

vector<int> preorder(Node *root)
{
    vector<int> trvl;
    if (root == NULL)
        return trvl;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        trvl.push_back(node->data);

        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
    return trvl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> trvl = preorder(root);
    for (auto x : trvl)
    {
        cout << x << " ";
    }
}