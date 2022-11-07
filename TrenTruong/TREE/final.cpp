#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct Node
{
    int LTAG, RTAG;
    int INFO;
    Node* LLINK, * RLINK;
    Node* next;
    Node()
    {
        LTAG = RTAG = 1;
        INFO = 0;
        LLINK = RLINK = NULL;
    }
};

struct LINKEDSTACK {
    Node* top;

    // cac ham nay bien doi qua sang queuce , dequece
    void init() {
        top = nullptr; // stack chua co phan tu nao het
    }
    bool push(Node* Y) {
        if (top == nullptr) {
            top = Y;
            top->next = nullptr;
            return true;
        }
        Y->next = top;
        top = Y;
        return true;
    }
    bool empty() {
        return top == NULL;
    }
    Node* deleteStack() {
        if (this->empty()) return nullptr;
        Node* result;
        result = (Node*)calloc(1, sizeof(Node));
        result->INFO = top->INFO; 
        Node* next = top->next;
        delete(top);
        top = next;
        return result;
    }

    Node* pop() {
        if (empty()) { return NULL; }
        else {
            Node* y = new Node;
            Node* p = new Node;
            y->next = NULL;
            p->next = NULL;
            y = top;
            p->INFO= top->INFO;
            top = top->next;
            delete y;
            return p;
        }
    }
    Node* Top() {
        if (empty())
            return nullptr;
        Node* p = new Node;
        p->INFO = top->INFO;
        p->LLINK = top->LLINK;
        p->RLINK = top->RLINK;
        p->LTAG = top->LTAG;
        p->RTAG = top->RTAG;
        return p;
    }
};
struct UnThreadBinaryNode
{
    Node* root;
    
    void create()
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
        LINKEDSTACK st;
        st.init();
        /* Push root Node into it */
        st.push(root);
       
        while (!st.empty())
        {
            /* Pop and print top node */
            Node* temp = st.Top();
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
        LINKEDSTACK st;
        st.init();
        Node* currNode = root;
        while (currNode != NULL || !st.empty())
        {
            while (currNode)
            {
                st.push(currNode);
                currNode = currNode->LLINK;
            }
            currNode = st.Top();
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
        LINKEDSTACK st1, st2;
        st1.init();
        st2.init();
        /* Push root Node into first stack */
        st1.push(root);

        while (!st1.empty())
        {
            /* Pop top node */
            Node* temp = st1.Top();
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
            Node* temp = st2.Top();
            cout << temp->INFO << " ";
            st2.pop();
        }
    }
};

struct ThreadBinaryTree
{
    Node* root;
    ThreadBinaryTree()
    {
        root = new Node();
        root->INFO = 999999; //nut gia
        root->RTAG = 0;
        root->LTAG = 1;
        root->LLINK = root;
        root->RLINK = root;
    }

    void create()
    {
        int n = 9;
        this->insert(6);
        this->insert(3);
        this->insert(1);
        this->insert(5);
        this->insert(8);
        this->insert(7);
        this->insert(11);
        this->insert(9);
        this->insert(13);
    }
    void insert(int data)
    {
        if (root->LLINK == root && root->RLINK == root)
        {
            Node* p = new Node();
            p->INFO = data;
            p->LLINK = root->LLINK;
            p->LTAG = root->LTAG;
            p->RTAG = 1;
            p->RLINK = root->RLINK;
            root->LLINK = p;
            root->LTAG = 0;
            return;
        }
        Node* cur = new Node;
        cur = root->LLINK;
        while (1)
        {
            if (cur->INFO < data)
            {
                Node* p = new Node();
                p->INFO = data;
                if (cur->RTAG == 1)
                {
                    p->RLINK = cur->RLINK;
                    p->RTAG = cur->RTAG;
                    p->LTAG = 1;
                    p->LLINK = cur;
                    cur->RTAG = 0;
                    cur->RLINK = p;
                    return;
                }
                else
                    cur = cur->RLINK;
            }
            if (cur->INFO > data)
            {
                Node* p = new Node();
                p->INFO = data;
                if (cur->LTAG == 1)
                {
                    p->LLINK = cur->LLINK;
                    p->LTAG = cur->LTAG;
                    p->RTAG = 1;
                    p->RLINK = cur;
                    cur->LTAG = 0;
                    cur->LLINK = p;
                    return;
                }
                else
                    cur = cur->LLINK;
            }
        }
    }
    Node* preorderSuccessor(Node* c)
    {
        if (c->LTAG == 0)
        {
            return c->LLINK;
        }
        while (c->RTAG == 1)
        {
            c = c->RLINK;
        }

        return c->RLINK;// return c;
    }
    void preorder()
    {
        Node* c = root->LLINK;
        while (c != root)
        {
            cout << " " << c->INFO;
            c = preorderSuccessor(c);
        }
    }
    Node* inorderSuccessor(Node* c)
    {
        if (c->RTAG == 1)
            return c->RLINK;
        else
            c = c->RLINK;
        while (c->LTAG == 0)
        {
            c = c->LLINK;
        }
        return c;
    }

    void inorder()
    {
        Node* c;
        c = root->LLINK;
        while (c->LTAG == 0)
            c = c->LLINK;
        while (c != root)
        {
            cout << " " << c->INFO;
            c = inorderSuccessor(c);
        }
    }
    void postorder()
    {
        /* Check Base Condition */
        if (root == NULL)
            return;
        /* Create an Empty Stack */
        LINKEDSTACK st1, st2;
        st1.init();
        st2.init();
        /* Push root Node into first stack */
        st1.push(root->LLINK);

        while (!st1.empty())
        {
            /* Pop top node */
            Node* temp = st1.Top();
            st1.pop();

            /* Push Popped Node into second stack */
            st2.push(temp);

            /* Push LLINK Child, if exists */
            if (temp->LLINK&&temp->LTAG == 0)
                st1.push(temp->LLINK);

            /* Push RLINK Child, if exists */
            if (temp->RLINK&&temp->RTAG == 0)
                st1.push(temp->RLINK);
        }
        /* Print Elements of second stack; which are stored in reverse postorder traversal */
        while (!st2.empty())
        {
            Node* temp = st2.Top();
            cout << temp->INFO << " ";
            st2.pop();
        }
    }


};
int main() {
   ThreadBinaryTree t1;
   t1.create();
   printf("-Thread binary tree: ");
   printf("\nThe Inorder Traversal of the Given Binary Tree is:\n");
   t1.inorder();
   printf("\nThe Preorder Traversal of the Given Binary Tree is:\n");
   t1.preorder();
   printf("\nThe Post Traversal of the Given Binary Tree is:\n");
   t1.postorder();
   printf("\n---------------------------------------------------------");
   printf("\n-UnThread binary tree: ");
   UnThreadBinaryNode t2;
   printf( "\nThe Preorder Traversal of the Given Binary Tree is:\n");
   t2.create();
   t2.preorder();
   printf("\nThe Inorder Traversal of the Given Binary Tree is:\n");
   t2.create();
   t2.inorder();
   printf("\nThe Postorder Traversal of the Given Binary Tree is:\n");
   t2.create();
   t2.postorder();
   return 0;
}
