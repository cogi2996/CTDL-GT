#include<bits/stdc++.h>
using namespace std;
// ======= KHAI BAO CUA TRUC DNAH SACH LIEN KET DON CAC SO NGUYEN ========
// khai bao mot node
struct node{
	int data;
	struct node *pNext;
};

typedef struct node NODE;// thay the struct node --> NODE

struct list{
	NODE *pHead; // node quan li dau danh sach
	NODE *pTail; // node quan li cuoi danh sach
};

typedef struct list LIST; // thay  the struct list --> LIST
// ======== KHOI TAO CAU TRUC DANH SACH LIEN KET DON CAC SO NGUYEN =====	
void khoitao(LIST &l)
{
	// cho hai node tro den    NULL - vi danh sach lien ket don chua co phan tu
	l.pHead = NULL;
	l.ptail = NULL; 
}
//  ham khoi tao 1 cai node
NODE *khoiTaoNode(int x)
{
	NODE *p = new NODE; // cap phat vung nho cho NODE p
	if(p == NULL)
	{     
		cout<<"\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyen gia tri x vao data
	p->pNext = NULL;  // dau tien khai bao thi node do chua lien ket den node nao het => con tro cua no se tro den NULL
	return p; // tra ve node p vua khoi tao	
}

// them node vao dau danh sach liens ket
void themVaoDau(LIST &l, NODE *p )
{
	// danh sach dang rong
	if(l.pHead == NULL)
	{
		l.pHead  = l.pTail = p; // node dau cung chinh la node cuoi va la p
		// ba node cùng một địa chỉ
	}
	else
	{
		p->pNext = l.pHead; // cho con tro cua node can them la node p lien ket den node dau - pHead
		l.pHead = p;  // cap nhat lai pHead chinh la node p 
	}
}

// them node vao cuoi dau danh sach liens ket
void themVaoCuoi(LIST &l, NODE *p )
{
	// danh sach dang rong
	if(l.pHead == NULL)
	{
		 l.pHead  = l.pTail = p; // node dau cung chinh la node cuoi va la p
	}
	else
	{
		l.pTail->pnext = p; // con tro cua pTail lien ket voi node p
		l.pTail =  p;  // cap nhat lai b p la node pTail
	}
}

// ham xuat danh sasch lien ket don
void xuatDanhSach(LIST l)
{
	for(NODE *k = l.pHead;k!=NUll;K = k->pNext)
	{ 
		cout<<k->data<<" ";
	}
}
int main()
{
	LIST l;
	khoiTao(l); // Khoi tao danh sach lien ket don	
	int n;
	cout<<"nhap so luong node can them ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cout<<"\nNhap gia tri so nguyen: ";
		NODE *p = khoiTaoNode(x); // khoi tao 1 cai node so nguyen
		themVaoDau(l,p); // them node P vao dau ds lien ket don
	}
	cout<<"\n\n\t Danh sach lien ket don: ";
}
