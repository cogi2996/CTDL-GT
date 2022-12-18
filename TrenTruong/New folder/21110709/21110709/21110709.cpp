#include <iostream>//21110709
using namespace std;
struct NODE
{
	int LTAG, RTAG;
	int INFO;
	NODE* LLINK, * RLINK;
};
struct DATA
{
	NODE* node;
	DATA* next;
};
struct Stack
{
	DATA* top;
	void init()
	{
		top = nullptr;
	}
	bool insert(DATA* Y)
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
	bool insertNODE(NODE* y)
	{
		DATA* data = (DATA*)malloc(sizeof(DATA));
		data->node = y;
		return this->insert(data);
	}
	bool isEmpty()
	{
		return top == nullptr;
	}
	DATA* deleteStack()
	{
		if (this->isEmpty())
			return nullptr;
		DATA* result;
		result = (DATA*)calloc(1, sizeof(DATA));
		result->node = top->node;
		DATA* next = top->next;
		delete (top);
		top = next;
		return result;
	}
};
struct UnThreaded
{
	NODE* root;
	void init()
	{
		root = nullptr;
	}
	void InOrder()
	{
		Stack s;
		s.init();
		NODE* P = this->root;
		while (P != nullptr || !s.isEmpty())
		{
			if (P == nullptr)
			{
				if (s.isEmpty())
					break;
				P = s.deleteStack()->node;
				cout << P->INFO << " ";
				P = P->RLINK;
			}
			else
			{
				s.insertNODE(P);
				P = P->LLINK;
			}
			if (P != nullptr)
				continue;
			if (s.isEmpty())
				break;
		}
	}
	void PostOrder()
	{
		Stack s;
		s.init();
		NODE* P = this->root;
		NODE* tmp;
		s.insertNODE(P);
		P = nullptr;
		while (s.isEmpty() == false)
		{
			tmp = s.top->node;
			if (P == nullptr)
			{
				if (tmp->LLINK != nullptr)
					s.insertNODE(tmp->LLINK);
				else if (tmp->RLINK != nullptr)
					s.insertNODE(tmp->RLINK);
				else
				{
					s.deleteStack();
					cout << tmp->INFO << " ";
				}
			}
			else if (P != nullptr)
			{
				if (P->LLINK == tmp || P->RLINK == tmp)
				{
					if (tmp->LLINK != nullptr)
						s.insertNODE(tmp->LLINK);
					else if (tmp->RLINK != nullptr)
						s.insertNODE(tmp->RLINK);
					else
					{
						s.deleteStack();
						cout << tmp->INFO << " ";
					}
				}
				else if (tmp->LLINK == P)
				{
					if (tmp->RLINK != nullptr)
					{
						s.insertNODE(tmp->RLINK);
					}
					else
					{
						s.deleteStack();
						cout << tmp->INFO << " ";
					}
				}
				else if (tmp->RLINK == P)
				{
					s.deleteStack();
					cout << tmp->INFO << " ";
				}
			}
			P = tmp;
		}
	}
	void PreOrder()
	{
		Stack s;
		DATA* data;
		s.init();
		NODE* P = this->root;
		s.insertNODE(P);
		while (!s.isEmpty())
		{
			P = s.deleteStack()->node;
			cout << P->INFO << " ";
			if (P->RLINK != nullptr)
			{
				s.insertNODE(P->RLINK);
			}
			if (P->LLINK != nullptr)
			{
				s.insertNODE(P->LLINK);
			}
		}
	}
};
struct Threaded
{
	NODE* root;
	void init()
	{
		root = nullptr;
	}
	NODE* nextNODEInOrder(NODE* P)
	{
		NODE* Q = P->RLINK;
		if (P->RTAG == 1)
			return Q;
		while (Q->LTAG == 0)
		{
			Q = Q->LLINK;
		}
		return Q;
	}
	NODE* leftNODE()
	{
		NODE* Q = root->LLINK;
		while (Q->LTAG != 1)
		{
			Q = Q->LLINK;
		}
		return Q;
	}
	void InOrder()
	{
		NODE* P = leftNODE();
		while (P != root)
		{
			cout << P->INFO << " ";
			P = nextNODEInOrder(P);
		}
	}
	void PreOrder(NODE* Y)
	{
		cout << Y->INFO << " ";
		if (Y->LTAG != 1)
			PreOrder(Y->LLINK);
		if (Y->RTAG != 1)
			PreOrder(Y->RLINK);
		return;
	}
	void PostOrder(NODE* Y)
	{
		if (Y->LTAG != 1)
			PostOrder(Y->LLINK);
		if (Y->RTAG != 1)
			PostOrder(Y->RLINK);
		cout << Y->INFO << " ";
		return;
	}
};
UnThreaded* build_unthread_tree()
{
	UnThreaded* tree;
	tree = (UnThreaded*)malloc(sizeof(UnThreaded));
	tree->init();
	NODE* A, * B, * C, * D, * E, * F, * G, * H, * J;
	A = (NODE*)malloc(sizeof(NODE));
	B = (NODE*)malloc(sizeof(NODE));
	C = (NODE*)malloc(sizeof(NODE));
	D = (NODE*)malloc(sizeof(NODE));
	E = (NODE*)malloc(sizeof(NODE));
	F = (NODE*)malloc(sizeof(NODE));
	G = (NODE*)malloc(sizeof(NODE));
	H = (NODE*)malloc(sizeof(NODE));
	J = (NODE*)malloc(sizeof(NODE));
	A->INFO = 8, B->INFO = 3, C->INFO = 10, D->INFO = 1, E->INFO = 6, F->INFO = 14, G->INFO = 4, H->INFO = 7, J->INFO = 13;
	A->LTAG = 0, A->RTAG = 0;
	B->LTAG = 0, B->RTAG = 0;
	C->LTAG = 0, C->RTAG = 0;
	D->LTAG = 0, D->RTAG = 0;
	E->LTAG = 0, E->RTAG = 0;
	F->LTAG = 0, F->RTAG = 0;
	G->LTAG = 0, G->RTAG = 0;
	H->LTAG = 0, H->RTAG = 0;
	J->LTAG = 0, J->RTAG = 0;
	tree->root = A;
	tree->root->LLINK = B, tree->root->RLINK = C;
	B->LLINK = D, B->RLINK = E;
	C->LLINK = nullptr, C->RLINK = F;
	D->LLINK = nullptr;
	D->RLINK = nullptr;
	E->LLINK = G, E->RLINK = H;
	F->LLINK = J, F->RLINK = nullptr;
	G->LLINK = nullptr, G->RLINK = nullptr;
	H->LLINK = nullptr, H->RLINK = nullptr;
	J->LLINK = nullptr, J->RLINK = nullptr;
	return tree;
}
Threaded* build_thread_tree_inorder()
{
	Threaded* tree;
	tree = (Threaded*)malloc(sizeof(Threaded));
	tree->init();
	NODE* A, * B, * C, * D, * E, * F, * G, * H, * J;
	A = (NODE*)malloc(sizeof(NODE));
	B = (NODE*)malloc(sizeof(NODE));
	C = (NODE*)malloc(sizeof(NODE));
	D = (NODE*)malloc(sizeof(NODE));
	E = (NODE*)malloc(sizeof(NODE));
	F = (NODE*)malloc(sizeof(NODE));
	G = (NODE*)malloc(sizeof(NODE));
	H = (NODE*)malloc(sizeof(NODE));
	J = (NODE*)malloc(sizeof(NODE));
	tree->root = (NODE*)malloc(sizeof(tree));
	A->INFO = 8, B->INFO = 3, C->INFO = 10, D->INFO = 1, E->INFO = 6, F->INFO = 14, G->INFO = 4, H->INFO = 7, J->INFO = 13;
	A->LTAG = 0, A->RTAG = 0;
	A->LLINK = B, A->RLINK = C;
	B->LTAG = 0, B->RTAG = 0;
	B->LLINK = D, B->RLINK = E;
	C->LTAG = 1, C->RTAG = 0;
	C->LLINK = A, C->RLINK = F;
	D->LTAG = 1, D->RTAG = 1;
	D->LLINK = tree->root, D->RLINK = B;
	E->LTAG = 0, E->RTAG = 0;
	E->LLINK = G, E->RLINK = H;
	F->LTAG = 0, F->RTAG = 1;
	F->LLINK = J, F->RLINK = tree->root;
	G->LTAG = 1, G->RTAG = 1;
	G->LLINK = B, G->RLINK = E;
	H->LTAG = 1, H->RTAG = 1;
	H->LLINK = E, H->RLINK = A;
	J->LTAG = 1, J->RTAG = 1;
	J->LLINK = A, J->RLINK = F;
	tree->root->LTAG = 0, tree->root->RTAG = 1;
	tree->root->LLINK = A, tree->root->RLINK = tree->root;
	return tree;
}
int main()
{
	UnThreaded* tree1 = build_unthread_tree();
	cout << "InOrder: ";
	tree1->InOrder();
	cout << endl;
	cout << "PreOrder: ";
	tree1->PreOrder();
	cout << endl;
	cout << "PostOrder: ";
	tree1->PostOrder();
	cout << endl;
	Threaded* tree2 = build_thread_tree_inorder();
	cout << "InOrder: ";
	tree2->InOrder();
	cout << endl;
	cout << "PreOrder: ";
	tree2->PreOrder(tree2->root->LLINK);
	cout << endl;
	cout << "PostOrder: ";
	tree2->PostOrder(tree2->root->LLINK);
}