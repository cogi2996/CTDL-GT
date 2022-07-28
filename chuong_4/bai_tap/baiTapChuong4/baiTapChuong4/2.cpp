#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *pNext;
};

typedef struct node NODE;

struct list {
	NODE* pHead;
	NODE* pTail;
};

typedef struct list LIST;

void initList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *initNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho de tao mot node moi";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addHeadList(LIST& l, NODE *p) // cai list co phead va pTail deu la con tro dia chi , nen thang p cung la con tro dia chi de de thuc hien phep toan
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addFinalList(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int findNode(LIST l, NODE* p)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == p->data)
		{
			return 1;
		}
	}
	return 0;
}

void eraseHead(LIST& l)
{
	if (l.pHead == NULL)
		return;
	NODE* p = l.pHead;
	l.pHead = p->pNext;
	delete p;
}

void eraseTail(LIST& l)
{
	if (l.pHead == NULL)
		return;
	if (l.pHead->pNext == NULL)
	{
		eraseHead(l);
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete k->pNext;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}
	}
}
void eraseNode(LIST&l,int x)
{
	// neu danh sach rong 
	if (l.pHead == NULL)
		return;
	 // neu node can xoa nam dau danh sach
	if (l.pHead->data == x)
	{
		eraseHead(l);
		return;
	}
	// neu phan tu nam o cuoi
	if (l.pTail->data == x)
	{
		eraseTail(l);
		return;
	}
	NODE* g = new NODE; // node g tro den node can xoa
	// duyet tu dau den cuoi danh sach lien ket don de tim
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		// phat hien phan tu can xoa
		if (k->data == x)
		{ 
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
}

void outPutList(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

void Menu(LIST l)
{
	int choice;
	do {
		cin >> choice;
		if (choice == 1)
		{
			int x;
			cin >> x;
			addHeadList(l,initNode(x));
		}
		else if (choice == 2)
		{
			int x;
			cin >> x;
			addFinalList(l, initNode(x));
		}
		else if (choice == 3)
		{
			outPutList(l);
		}
		else if (choice == 4)
		{
			int x;
			cout << "Nhap phan tu can xoa:  ";
			cin >> x;
			eraseNode(l, x);
		}
	} while (choice);
}

int main()
{
	LIST list;
	initList(list);
	Menu(list);
}