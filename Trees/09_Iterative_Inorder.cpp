/*Iterative Inorder Traveral
    TC -> O(N)
    SC -> O(H)
*/

#include <iostream>
#include <vector>
#include <stack>
#include "Tree.cpp"
using namespace std;
vector<int> inorder(Node *root)
{
    vector<int> trvl;
    stack<Node *> st;
    Node *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            trvl.push_back(node->data);
            node = node->right;
        }
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

    vector<int> trvl = inorder(root);
    for (auto x : trvl)
    {
        cout << x << " ";
    }
}