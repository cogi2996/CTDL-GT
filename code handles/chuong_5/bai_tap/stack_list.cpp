#include<iostream>
using namespace std;

// khai bao cau truc cua 1 cai node trong stack
struct node {
	int data; // stack dang chua cac so nguyen
	struct node* pNext; // con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;

NODE* initNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de thuc hien ";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
// khai bao cau truc cua stack
struct stack {
	NODE* pTop; // dung con tro dau de quan li stack
};
typedef struct stack STACK;

//ham khoi tao stack
void initStack(STACK &s)
{
	s.pTop = NULL;
}

// kiem tra STACK co rong hay khong
bool isEmpty(STACK s)
{
	if (s.pTop == NULL)
		return true;
	return false; // danh sach co phan tu
} 

// them mot phan tu vao dau STACK (LIFO) 
bool push(STACK& s, NODE *p)
{
	if (p == NULL)
		return false;
	if (isEmpty(s))
	{
		s.pTop = p; // node p chinh la node dau stack
	}
	else
	{
		p->pNext = s.pTop; // cho con tro cua node p tro den node dau danh sach <=> tao lien ket
		s.pTop = p; // cap nhat lai node dau
	}
}
// lay phan tu dau STACK  va huy no di
bool pop(STACK& s,int &x) // x chinh la gia tri can lay trong node
{
	if (isEmpty(s))
		return false;
	else
	{
		NODE* p = s.pTop; // node p la node the mang cho Top , de ti nua t xoa cai top cu~
		x = p->data;// gan gia tri cua node dau stack vao bien x
		s.pTop = s.pTop->pNext;// cap nhat node dau stack la node tiep theo
		delete p; // xoa node dau cu~ stack	
	}
	return true; // lay phan tu dau stack thanh cong
}

bool top(STACK& s, int &x)
{
	if (isEmpty(s))
		return false;
	x = s.pTop->data; // lay gia tri cua phan tu dau STACK ra de xem
	return true;
}

// xuat Stack
void outPutStack(STACK s)
{
	while (!isEmpty(s) )
	{
		int x;
		pop(s, x);
		cout << x << " ";
	}
	if (isEmpty(s))
	{
		cout << "\nDanh sach dang rong";
	}
}
void inPutStack(STACK& s)
{
	int choice;
	do {
		system("cls");
		cout << endl << "=====================Menu=====================";
		cout << endl << "0.Exit";
		cout << endl << "1.Them phan tu vao stack - PUSH";
		cout << endl << " 2.Xuat danh sach ra man hinh - POP";
		cout << endl << "3.Xem thong tin phan tu dau stack - TOP";
		cout << endl << "=====================Menu=====================";
		cout << endl;
		cin >> choice;
		if (choice == 1)
		{
			int x;
			cout << endl << "Nhap phan tu can them";
			cin >> x;
			push(s, initNode(x));
		}
		else if (choice == 2)
		{
			outPutStack(s);
			system("pause");
		}
		else if (choice == 3)
		{
			int x;
			top(s, x);
			cout << "\nPhan tu dau danh sach la: " << x<<endl;
			system("pause");
		}
		else
			break;
	} while (choice);
}
int main()
{
	STACK s;
	initStack(s);
	inPutStack(s);
	system("pause");
}