#include <iostream>
using namespace std;

struct Node
{
    int lbit, rbit;
    int value;
    Node* left, * right;
    Node()
    {
        lbit = rbit = 0;
        value = 0;
        left = right = NULL;
    }
};

struct ThreadBinaryTree
{
    Node* root;
    ThreadBinaryTree()
    {
        root = new Node();
        root->value = 9999;
        root->rbit = 1;
        root->lbit = 0;
        root->left = root;
        root->right = root;
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
        if (root->left == root && root->right == root)
        {

            Node* p = new Node();
            p->value = data;
            p->left = root->left;
            p->lbit = root->lbit;
            p->rbit = 0;
            p->right = root->right;
            root->left = p;
            root->lbit = 1;
            return;
        }
        Node* cur = new Node;
        cur = root->left;
        while (1)
        {
            if (cur->value < data)
            {
                Node* p = new Node();
                p->value = data;
                if (cur->rbit == 0)
                {
                    p->right = cur->right;
                    p->rbit = cur->rbit;
                    p->lbit = 0;
                    p->left = cur;
                    cur->rbit = 1;
                    cur->right = p;
                    return;
                }
                else
                    cur = cur->right;
            }
            if (cur->value > data)
            {
                Node* p = new Node();
                p->value = data;
                if (cur->lbit == 0)
                {
                    p->left = cur->left;
                    p->lbit = cur->lbit;
                    p->rbit = 0;
                    p->right = cur;
                    cur->lbit = 1;
                    cur->left = p;
                    return;
                }
                else
                    cur = cur->left;
            }
        }
    }
    Node* preorderSuccessor(Node* c)
    {
        if (c->lbit == 1)
        {
            return c->left;
        }
        //in 
        //pop neu khac root
        // in neu pop khac in tren 

        while (c->rbit == 0)
        {
            c = c->right;
        }
        
        return c->right;// return c;
    }
    void preorder()
    {
        Node* c = root->left;
        while (c != root)
        {
            cout << " " << c->value;
            c = preorderSuccessor(c);
        }
    }
    Node* inorderSuccessor(Node* c)
    {
        if (c->rbit == 0)
            return c->right;
        else
            c = c->right;
        while (c->lbit == 1)
        {
            c = c->left;
        }
        return c;
    }
   
    void inorder()
    {
        Node* c;
        c = root->left;
        while (c->lbit == 1)
            c = c->left;
        while (c != root)
        {
            cout << " " << c->value;
            c = inorderSuccessor(c);
        }
    }
   

};

int main()
{
    ThreadBinaryTree t1;
    t1.create();
    cout << "Inorder Traversal of DTBST\n";
    t1.inorder();
    cout << "\nPreorder Traversal of DTBST\n";
    t1.preorder();
    return 0;
}