#include<iostream>
using namespace std;
// ======= KHAI BAO CUA TRUC DNAH SACH LIEN KET DON CAC SO NGUYEN ========
// khai bao mot node
struct node {
	int data;
	struct node* pNext;
};

typedef struct node NODE;// thay the struct node --> NODE

struct list {
	NODE* pHead; // node quan li dau danh sach
	NODE* pTail; // node quan li cuoi danh sach
};

typedef struct list LIST; // thay  the struct list --> LIST
// ======== KHOI TAO CAU TRUC DANH SACH LIEN KET DON CAC SO NGUYEN =====	
void khoiTao(LIST& l)
{
	// cho hai node tro den    NULL - vi danh sach lien ket don chua co phan tu
	l.pHead = NULL;
	l.pTail = NULL;
}
//  ham khoi tao 1 cai node
NODE* khoiTaoNode(int x)
{
	NODE* p = new NODE; // cap phat vung nho cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyen gia tri x vao data
	p->pNext = NULL;  // dau tien khai bao thi node do chua lien ket den node nao het => con tro cua no se tro den NULL
	return p; // tra ve node p vua khoi tao	
}

// them node vao dau danh sach liens ket
void themVaoDau(LIST& l, NODE* p)
{
	// danh sach dang rong
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node dau cung chinh la node cuoi va la p
	}
	else
	{
		p->pNext = l.pHead; // cho con tro cua node can them la node p lien ket den node dau - pHead
		l.pHead = p;  // cap nhat lai pHead chinh la node p 
	}
}

// them node vao cuoi dau danh sach liens ket
void themVaoCuoi(LIST& l, NODE* p)
{
	// danh sach dang rong
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node dau cung chinh la node cuoi va la p
	}
	else
	{
		l.pTail->pNext = p; // con tro cua pTail lien ket voi node p
		l.pTail = p;  // cap nhat lai b p la node pTail
	}
}

// ham xuat danh sasch lien ket don
void xuatDanhSach(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}
// them node p vao sau node q ( nam trong danh sach lien ket don)
void ThemNode_p_VaoSauNode_q(LIST& l, NODE* p)
{
	int x;
	cout << "Nhap gia tri node q: ";
	cin >> x;
	NODE* q = khoiTaoNode(x);
	// Neu danh sach chi co mot phan tu thi phan tu do cung chinh la node q ==>
	//bai toan tro thanh ki thuat them vao cuoi danh sach
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		themVaoCuoi(l, p);
	}
	else // neu co nhieu phan tu
	{
		// duyet tu dau danh sach den cuoi danh sach de tim ndoe q
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			// neu node q co ton tai thi ...
			if (q->data == k->data)
			{
				NODE* h = khoiTaoNode(p->data); // khoi tao node h mới để thêm vào sau node q , h là copy mỗi lần chạy loop của p
				NODE* g = k->pNext; // g trỏ đến node sau node q 
				h->pNext = g; // b1: Tạo mối liên kết từ node h đến node g 
				// đến node nằm sau node q <=> cũng chính là tạo mối liên kết từ node h 
				k->pNext = h; // Bước 2:Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h

			}
		}
	}
}
// ham xoa phan tu dau
void xoaDau(LIST& l)
{
	// neu danh sach rong 
	if (l.pHead == NULL)
	{
		return;
	}
	NODE* p = l.pHead; // node p la node se xoa ( bien trung gian luu tru lai node dau cu)
	l.pHead = l.pHead->pNext;// cap nhat lai l.pHead la phan tu thu 2
	delete p;// node the mang cho node 1 ( tuy the mang nhung node 1 bi dele that
	// vi p no tro den node 1

}



void Menu(LIST& l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t=====================Menu=====================";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau noded q trong danh sach";
		cout << "\nt4. Xoa dau";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t=====================End=====================";
		cout << "\nNhap lua chon";
		cin >> luachon;
		if (luachon < 0 || luachon >4)
		{
			cout << "Lua chon khong hop le. Xin kiem tra lai!";
			system("pause");
		}
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE* p = khoiTaoNode(x); // khoi tao mot node
			themVaoCuoi(l, p); //  Them mot node vao cuoi danh sach
		}
		else if (luachon == 2)
		{
			xuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\n Nhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE* p = khoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // them node p vao sau node q trong danh sach l 
		}
		else if (luachon == 4)
		{
			xoaDau(l);
		}
		else
		{
			break; //thoat khoi vong lap hien tai
		}
	}
}

// ham tim gia tri lon nhat trong danh sach
int timMax(LIST  l)
{
	int MAX = l.pHead->data;
	for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext)
	{
		MAX = max(MAX, k->data);
	}
	return MAX;
}
int main()
{
	LIST l;
	khoiTao(l); // Khoi tao danh sach lien ket don	
	Menu(l);
	return 0;


}
