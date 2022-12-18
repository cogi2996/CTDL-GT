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
// khai bao cau truc cua queue
struct queue {
	NODE* pHead; // dung con tro dau de quan li queue
	NODE* pTail;// dung con tro cuoi de quan li queue
};
typedef struct queue QUEUE;

//ham khoi tao queue
void initQueue(QUEUE& q )
{
	q.pHead = NULL;
	q.pTail = NULL; 
}

// kiem tra STACK co rong hay khong
bool isEmpty(QUEUE q)
{
	if (q.pHead == NULL)
		return true;
	return false ; // danh sach co phan tu
}

// them mot phan tu vao cuoi QUEUE (FIFO) 
bool push(QUEUE& q,NODE* p)
{
	if (p == NULL)
		return false;
	if (isEmpty(q))
	{
		q.pHead = q.pTail = p; // node p chinh la node dau va node cuoi
	}
	else
	{
		// them vao cuoi danh sach
		q.pTail->pNext = p; // lien ket con tro cuoi cua danh sach voi phan tu p can them vao
		q.pTail = p; // cap nhat lai con tro cuoi chinh la p
	}
}
// lay phan tu dau QUEUE va huy no di
bool pop(QUEUE& q, int& x) // x chinh la gia tri can lay trong node
{
	if (isEmpty(q))
		return false;
	else
	{
		NODE* p = q.pHead; // node p la node the mang cho Top , de ti nua t xoa cai top cu~
		x = p->data;// gan gia tri cua node dau stack vao bien x
		q.pHead = q.pHead->pNext;// cap nhat node dau stack la node tiep theo
		delete p; // xoa node dau queue vua lay
	}
	return true; // lay phan tu dau queue thanh cong
}

bool top(QUEUE& q, int& x)
{
	if (isEmpty(q))
		return false;
	x = q.pHead->data; // lay gia tri cua phan tu dau STACK ra de xem
	return true;
}

// xuat QUEUE
void outPutQueue(QUEUE q)
{
	while (!isEmpty(q))
	{
		int x;
		pop(q, x);
		cout << x << " ";
	}
	if (isEmpty(q))
	{
		cout << "\nDanh sach dang rong";
	}
}
void inPutQueue(QUEUE &q)
{
	int choice;
	do {
		system("cls");
		cout << endl << "=====================Menu=====================";
		cout << endl << "0.Exit";
		cout << endl << "1.Them phan tu vao queue - PUSH";
		cout << endl << " 2.Xuat danh sach ra man hinh - POP";
		cout << endl << "3.Xem thong tin phan tu dau queue- TOP";
		cout << endl << "=====================Menu=====================";
		cout << endl;
		cin >> choice;
		if (choice == 1)
		{
			int x;
			cout << endl << "Nhap phan tu can them";
			cin >> x;
			push(q, initNode(x));
		}
		else if (choice == 2)
		{
			outPutQueue(q);
			system("pause");
		}
		else if (choice == 3)
		{
			int x;
			top(q, x);
			cout << "\nPhan tu dau danh sach la: " << x << endl;
			system("pause");
		}
		else
			break;
	} while (choice);
}
int main()
{
	QUEUE q;
	initQueue(q);
	inPutQueue(q);
	system("pause");
}