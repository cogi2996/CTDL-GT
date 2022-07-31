#include<iostream>
using namespace std;
#define MAX 100

struct stack {
	int A[MAX]; // array cac phan tu cua ngan xep
	int top;// chi so phan dinh dau cua ngan xep
};

typedef struct stack STACK;

void initStack(STACK& s)
{
	s.top = -1; // ngan xep rong
}

// check ngan xep rong
int isEmptyStack(STACK& s)
{
	if (s.top == -1)
		return 1; 
	return 0;
}

// kiem tra stack co day hay chua
int isFullStack(STACK& s)
{
	if (s.top == MAX - 1)
		return 1;
	return 0;
}

// them mot phan tu vao dau stack

void push(STACK &s,int x) {
	if (isFullStack(s))
		cout << "\nNgan xep day";
	else
	{
		s.A[++s.top] = x;
	}
}
//lay thong tin phan tu dau danh sach
int top(STACK s)
{
	return s.A[s.top];
}
// lay va huy phan tu o dau ngan xep pop
int pop(STACK& s)
{
	return  s.A[s.top--];
}

void menu(stack& s)
{
	cout << "here";
	int choice;
	do {
		system("cls");
		cout << "=====================Menu=====================";
		cout << "\n1.Them mot phan tu vao trong stack";
		cout << "\n2.Lay phan tu dau tien trong stack";
		cout << "\n3.Xuat danh sach ra man hinh";
		cout << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				int x;
				cout << "Nhap phan tu can them: "; cin >> x;
				push(s,x);
				break;
			}
			case 2:
			{
				cout << top(s);
				cout << endl;
				system("pause"); 
				break;
			}
			case 3:
			{
				while (!isEmptyStack(s))
				{
					cout << pop(s) << " ";
				}
				cout << endl;
				system("pause");
				break;
			}
		}
	} while (choice);
}
int main()
{
	STACK stack;
	initStack(stack);
	menu(stack);
}
