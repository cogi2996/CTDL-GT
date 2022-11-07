#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int LTAG, RTAG;
    char INFO;
    Node *LLINK, *RLINK;
    Node *next;
    Node()
    {
        LTAG = RTAG = 1;
        INFO = 0;
        LLINK = RLINK = NULL;
    }
};

struct LINKEDSTACK
{
    Node *top;
    void init()
    {
        top = nullptr;
    }
    bool push(Node *Y)
    {
        if (top == nullptr)
        {
            top = Y;
            top->next = nullptr;
            return true;
        }
        Y->next = top;
        top = Y;
        return true;
    }
    bool empty()
    {
        return top == nullptr;
    }
    Node *deleteStack()
    {
        if (this - empty())
            return nullptr;
        Node *result = new Node;

        result->INFO = top->INFO;
        Node *next = top->next;
        delete (top);
        top = next;
        return result;
    }

    Node *pop()
    {
        if (empty())
        {
            return NULL;
        }
        else
        {
            Node *y = new Node;
            Node *p = new Node;
            y->next = NULL;
            p->next = NULL;
            y = top;
            p->INFO = top->INFO;
            top = top->next;
            delete y;
            return p;
        }
    }
    Node *Top()
    {
        if (empty())
            return nullptr;
        Node *p = new Node();
        p->INFO = top->INFO;
        p->LLINK = top->LLINK;
        p->RLINK = top->RLINK;
        p->RTAG = top->RTAG;
        p->LTAG = top->LTAG;
        return p;
    }
};
struct UnThreadBinaryTree
{
    Node *root;

    void create()
    {
        root = NULL;
        root = new Node();
        root->INFO = 'F';
        root->LLINK = new Node();
        root->LLINK->INFO = 'C';
        root->RLINK = new Node();
        root->RLINK->INFO = 'H';
        root->LLINK->LLINK = new Node();
        root->LLINK->LLINK->INFO = 'A';
        root->LLINK->RLINK = new Node();
        root->LLINK->RLINK->INFO = 'E';
        root->RLINK->LLINK = new Node();
        root->RLINK->LLINK->INFO = 'G';
        root->RLINK->RLINK = new Node();
        root->RLINK->RLINK->INFO = 'K';
        root->RLINK->RLINK->LLINK = new Node();
        root->RLINK->RLINK->LLINK->INFO = 'I';
        root->RLINK->RLINK->RLINK = new Node();
        root->RLINK->RLINK->RLINK->INFO = 'M';
    }
    void preorder()
    {
        if (root == NULL)
            return;
        LINKEDSTACK st;
        st.init();
        st.push(root);

        while (!st.empty())
        {
            Node *temp = st.Top();
            st.pop();
            printf("%c ", temp->INFO);
            if (temp->RLINK)
                st.push(temp->RLINK);
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
        Node *currNode = root;
        while (currNode != NULL || !st.empty())
        {
            while (currNode)
            {
                st.push(currNode);
                currNode = currNode->LLINK;
            }
            currNode = st.Top();
            st.pop();
            printf("%c ", currNode->INFO);
            currNode = currNode->RLINK;
        }
    }
    void postorder()
    {
        if (root == NULL)
            return;
        LINKEDSTACK st1, st2;
        st1.init();
        st2.init();
        st1.push(root);

        while (!st1.empty())
        {
            Node *temp = st1.Top();
            st1.pop();
            st2.push(temp);
            if (temp->LLINK)
                st1.push(temp->LLINK);
            if (temp->RLINK)
                st1.push(temp->RLINK);
        }
        while (!st2.empty())
        {
            Node *temp = st2.Top();
            printf("%c ", temp->INFO);
            st2.pop();
        }
    }
};

struct ThreadBinaryTree
{
    Node *root;
    ThreadBinaryTree()
    {
        root = new Node();
        root->INFO = 'Z';
        root->RTAG = 0;
        root->LTAG = 1;
        root->LLINK = root;
        root->RLINK = root;
    }

    void create()
    {
        int n = 9;
        this->insert('F');
        this->insert('C');
        this->insert('A');
        this->insert('E');
        this->insert('H');
        this->insert('G');
        this->insert('K');
        this->insert('I');
        this->insert('M');
    }
    void insert(int data)
    {
        if (root->LLINK == root && root->RLINK == root)
        {
            Node *p = new Node();
            p->INFO = data;
            p->LLINK = root->LLINK;
            p->LTAG = root->LTAG;
            p->RTAG = 1;
            p->RLINK = root->RLINK;
            root->LLINK = p;
            root->LTAG = 0;
            return;
        }
        Node *cur = new Node;
        cur = root->LLINK;
        while (1)
        {
            if (cur->INFO < data)
            {
                Node *p = new Node();
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
                Node *p = new Node();
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
    Node *preorderSuccessor(Node *c)
    {
        if (c->LTAG == 0)
        {
            return c->LLINK;
        }
        while (c->RTAG == 1)
        {
            c = c->RLINK;
        }
        return c->RLINK;
    }
    void preorder()
    {
        Node *c = root->LLINK;
        while (c != root)
        {
            printf("%c ", c->INFO);
            c = preorderSuccessor(c);
        }
    }
    Node *inorderSuccess(Node *c)
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
        Node *c = root->LLINK;
        c = root->LLINK;
        while (c->LTAG == 0)
            c = c->LLINK;
        while (c != root)
        {
            printf("%c ", c->INFO);
            c = inorderSuccess(c);
        }
    }
    void postorder()
    {
        if (root == NULL)
            return;
        LINKEDSTACK st1, st2;
        st1.init();
        st2.init();
        st1.push(root->LLINK);

        while (!st1.empty())
        {
            Node *temp = st1.Top();
            st1.pop();
            st2.push(temp);
            if (temp->LLINK && temp->LTAG == 0)
                st1.push(temp->LLINK);

            if (temp->RLINK && temp->RTAG == 0)
                st1.push(temp->RLINK);
        }
        while (!st2.empty())
        {
            Node *temp = st2.Top();
            printf("%c ", temp->INFO);
            st2.pop();
        }
    }
};
int main()
{
    ThreadBinaryTree t1;
    t1.create();
    printf("-Thread binary tree: ");
    printf("\nThe Perorder Traversal of the Given Tree is:\n");
    t1.preorder();
    printf("\nThe Inorder Traversal of the Given Tree is:\n");
    t1.inorder();
    printf("\nThe Postorder Traversal of the Given Tree is:\n");
    t1.postorder();
    printf("\n---------------------------------------------------");
    printf("\n-UnThread binary tree: ");
    UnThreadBinaryTree t2;
    printf("\nThe Perorder Traversal of the Given Tree is:\n");
    t2.create();
    t2.preorder();
    printf("\nThe Inorder Traversal of the Given Tree is:\n");
    t2.create();
    t2.inorder();
    printf("\nThe Postorder Traversal of the Given Tree is:\n");
    t2.create();
    t2.postorder();
    return 0;
}