/* C++ Program to implement inorder tree traversal using stack*/
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int ele)
    {
        data = ele;
        left = NULL;
        right = NULL;
    }
} Node;

struct UnThreadBinaryNode
{
    Node *root;
    UnThreadBinaryNode()
    {
        root = NULL;
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        root->left->right->left = new Node(8);
        root->right->left->right = new Node(9);
    }
    
    void preorder()
    {
        /* Check Base Condition */
        if (root == NULL)
            return;

        /* Create an Empty Stack */
        stack<Node *> st;

        /* Push root Node into it */
        st.push(root);

        while (!st.empty())
        {
            /* Pop and print top node */
            Node *temp = st.top();
            st.pop();
            cout << temp->data << " ";

            /* Push Right Child, if exists */
            if (temp->right)
                st.push(temp->right);

            /* Push Left Child, if exists */
            if (temp->left)
                st.push(temp->left);
        }
    }
    void inorder()
    {
        if (root == NULL)
            return;
        stack<Node *> st;
        Node *currNode = root;
        while (currNode != NULL || !st.empty())
        {
            while (currNode)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            cout << currNode->data << " ";
            currNode = currNode->right;
        }
    }
    void postorder()
    {
        /* Check Base Condition */
        if (root == NULL)
            return;

        /* Create an Empty Stack */
        stack<Node *> st1, st2;

        /* Push root Node into first stack */
        st1.push(root);

        while (!st1.empty())
        {
            /* Pop top node */
            Node *temp = st1.top();
            st1.pop();

            /* Push Popped Node into second stack */
            st2.push(temp);

            /* Push Left Child, if exists */
            if (temp->left)
                st1.push(temp->left);

            /* Push Right Child, if exists */
            if (temp->right)
                st1.push(temp->right);
        }

        /* Print Elements of second stack; which are stored in reverse postorder traversal */
        while (!st2.empty())
        {
            Node *temp = st2.top();
            cout << temp->data << " ";
            st2.pop();
        }
    }
};

int main()
{
    UnThreadBinaryNode t1;
    cout << "The Inorder Traversal of the Given Binary Tree is: ";
    t1.preorder();
    /* Calling function to perform inorder traversal*/
}