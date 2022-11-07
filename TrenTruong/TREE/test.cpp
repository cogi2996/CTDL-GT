/* C++ Program to implement inorder tree traversal using stack*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int LTAG, RTAG;
    int INFO;
    Node* LLINK, * RLINK;
    Node()
    {
        LTAG = RTAG = 0;
        INFO = 0;
        LLINK = RLINK = NULL;
    }
};

struct UnThreadBinaryNode
{
    Node *root;
    UnThreadBinaryNode()
    {
        root = NULL;
        root = new Node();
        root->INFO = 1;
        root->LLINK = new Node();
        root->LLINK->INFO = 2;
        root->RLINK = new Node();
        root->RLINK->INFO = 3;
        root->LLINK->LLINK = new Node();
        root->LLINK->LLINK->INFO = 4;
        root->LLINK->RLINK = new Node();
        root->LLINK->RLINK->INFO = 5;
        root->RLINK->LLINK = new Node();
        root->RLINK->LLINK->INFO = 6;
        root->RLINK->RLINK = new Node();
        root->RLINK->RLINK->INFO = 7;
        root->LLINK->RLINK->LLINK = new Node();
        root->LLINK->RLINK->LLINK->INFO = 8;
        root->RLINK->LLINK->RLINK = new Node();
        root->RLINK->LLINK->RLINK->INFO = 9;
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
            cout << temp->INFO << " ";

            /* Push RLINK Child, if exists */
            if (temp->RLINK)
                st.push(temp->RLINK);

            /* Push LLINK Child, if exists */
            if (temp->LLINK)
                st.push(temp->LLINK);
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
                currNode = currNode->LLINK;
            }
            currNode = st.top();
            st.pop();
            cout << currNode->INFO << " ";
            currNode = currNode->RLINK;
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

            /* Push LLINK Child, if exists */
            if (temp->LLINK)
                st1.push(temp->LLINK);

            /* Push RLINK Child, if exists */
            if (temp->RLINK)
                st1.push(temp->RLINK);
        }

        /* Print Elements of second stack; which are stored in reverse postorder traversal */
        while (!st2.empty())
        {
            Node *temp = st2.top();
            cout << temp->INFO << " ";
            st2.pop();
        }
    }
};

int main()
{
    UnThreadBinaryNode t1;
    cout << "The Inorder Traversal of the Given Binary Tree is: ";
    t1.inorder();
    /* Calling function to perform inorder traversal*/
}