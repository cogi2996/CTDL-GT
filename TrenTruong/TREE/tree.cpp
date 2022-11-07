#include<bits/stdc++.h>
using namespace std;
struct CARD {
	int TAG;
	int SUIT;
	int RANK;
	CARD* next;
	char TITILE[255];
};

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

CARD* convert(Node* y)
{
	CARD* p = new CARD;
	p->next = NULL;
	p->RANK = y->INFO;
	return p;
}
struct LINKEDSTACK {
	CARD* top;
	
	// cac ham nay bien doi qua sang queuce , dequece
	void init() {
		top = nullptr; // stack chua co phan tu nao het
	}
	bool insert(CARD* Y) {
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
	CARD* deleteStack() {
		if (this->isEmpty()) return nullptr;
		CARD* result;
		result = (CARD*)calloc(1, sizeof(CARD));
		result->RANK = top->RANK; result->SUIT = top->SUIT;
		CARD* next = top->next;
		delete(top);
		top = next;
		return result;
	}
	bool push(CARD* Y) {
		if (Y == NULL) return NULL;
		if (isEmpty()) {
			top = Y;
			return true;
		}
		else
		{
			Y->next = top;
			top = Y;
		}
	}
	CARD* pop() {
		if (isEmpty()) { return NULL; }
		else {
			CARD* y = new CARD;
			CARD* p = new CARD;
			y->next = NULL;
			p->next = NULL;
			y = top;
			p->RANK = top->RANK;
			top = top->next;
			delete y;
			return p;
		}
	}
	CARD* Top() {
		if (isEmpty())
			return nullptr;
		return top;
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
        LINKEDSTACK st;

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
        LINKEDSTACK st;
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
        LINKEDSTACK st1, st2;

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

int main() {
	LINKEDSTACK Stack;
	Stack.init();
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		Node* C1;
		C1 = (Node*)malloc(sizeof(Node));
		C1->INFO= i;
		Stack.insert(convert(C1));

	}
	printf("\ndone \n");
	for (int i = 0; i < 10; i++) {
		printf("%d,", Stack.pop()->RANK);
	}
	return 0;

}