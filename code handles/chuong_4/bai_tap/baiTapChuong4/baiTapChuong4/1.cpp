#include<iostream>
using namespace std;

struct node {
	int data;
	struct node* pNext;
};

typedef struct node NODE;

struct list {
	NODE* pHead;
	NODE* pTail;
};

typedef struct list LIST;

void intiList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* intiNode(int x) // tra ve con tro NODE
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addHeadList(LIST& l, NODE *p)
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
void outPutList(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data<<" ";
	}
}

void Menu(LIST l)
{
	int choice;
	do {
		system("cls");
	cout << "=========================Menu=========================";
		cout << "\n\t.0 Exit";
		cout << "\n\t.1 Them vao cuoi danh sach";
		cout << "\n\t.2 Them vao dau danh sach";
		cout << "\n\t.3 Xuat danh sach ra man hinh\n";
		cout << "-->Nhap lua chon: ";
		cin >> choice;
		if (choice == 1)
		{
			int x;
			cin >> x;
			NODE *p = intiNode(x);
			addFinalList(l, p);
		} 
		else if (choice == 2)
		{
			int x; 
			cin >> x;
			addHeadList(l, intiNode(x));
		}
		else if(choice == 3)
		{
			outPutList(l);
			system("pause");
		}
		else if(choice ==0)
		{
			cout << "exited";
			break;
		}
		else {
			cout << "\n\t\t-->Lua chon khong hop le";
			choice = 0;
		}
		
	} while (choice);
}
int main()
{
	LIST list;
	intiList(list);
	Menu(list);
}