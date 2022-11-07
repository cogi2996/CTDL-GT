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
				NODE* h = khoiTaoNode(p->data); // khoi tao node h má»›i Ä‘á»ƒ thÃªm vÃ o sau node q , h lÃ  copy má»—i láº§n cháº¡y loop cá»§a p
				NODE* g = k->pNext; // g trá» Ä‘áº¿n node sau node q 
				h->pNext = g; // b1: Táº¡o má»‘i liÃªn káº¿t tá»« node h Ä‘áº¿n node g 
				// Ä‘áº¿n node náº±m sau node q <=> cÅ©ng chÃ­nh lÃ  táº¡o má»‘i liÃªn káº¿t tá»« node h 
				k->pNext = h; // BÆ°á»›c 2:Táº¡o má»‘i liÃªn káº¿t tá»« node q Ä‘áº¿n node h <=> chÃ­nh lÃ  node k Ä‘áº¿n node h

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
// Xoa cuoi
void xoaCuoi(LIST& l)
{
	// neu danh sach rong 
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->pNext == NULL)
	{
		xoaDau(l);
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL; // cho con tro cua node ke cuoi tro den NULL
			l.pTail = k; // cap nhat lai l.pTail
			return;
		}
	}
}

// ham xoa 1 node nam sau node q trong danh sach
void xoaSauNodeq(LIST& l, NODE* q)
{
	// duyet danh sach tim node q
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		// phat hien ra q
		if (k->data == q->data)
		{
			NODE* g = k->pNext; // node g cung chinh nam sau node k(q) ( cung chinh la node se xoa)
			k->pNext = g->pNext; // cap nhat moi lien ket giua node k(q) voi node sau node g
			delete g;
		}
	}
}

void quickSort(LIST& l)
{
	LIST l1, l2;
	NODE* pivot, * p; // phan tu cam canh va bien chay 
	khoiTao(l1);
	khoiTao(l2);
	// truong hop danh sach rong hoac co 1 phan tu
	if (l.pHead == l.pTail)
	{
		return;
	}
	// truong hop danh sach thanh 2 danh sach con
	pivot = l.pHead; // phan tu thu 1
	p = l.pHead->pNext; // phan tu thu 2
	while (p != NULL)
	{
		NODE* q = p;
		p = p->pNext; // phan tu thu 3 cho loop sau 
		q->pNext = NULL; // de them vao danh sach moi thi node phai moi do phai tro ve NULL nhu dinh nghia tao 1 node
		if (q->data < pivot->data)
			themVaoCuoi(l1, q); // them q vao cuoi list 
		else
			themVaoCuoi(l2, q);
	};
	// goi de quy sap xep cho cac danh sach con
	quickSort(l1);
	quickSort(l2);
	// ghep noi l1 voi pivot
	if (l1.pHead != NULL)
	{
		l.pHead = l1.pHead;
		l1.pTail->pNext = pivot;
	}
	else
	{
		l.pHead = pivot;
	}
	// ghep noi pivot voi list 2
	pivot -> pNext = l2.pHead;
	if (l2.pHead != NULL)
	{
		l.pTail = l2.pTail;
	}
	else
		l.pTail = pivot; // neu khong co danh sach l1, l2 thi head === Tail === pivot

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
		cout << "\n\t4. Xoa dau";
		cout << "\n\t5. Xoa cuoi";
		cout << "\n\t6. Xoa node sau node q";
		cout << "\n\t7. Sap xep danh sach";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t=====================End=====================";
		cout << "\nNhap lua chon";
		cin >> luachon;
		if (luachon < 0 || luachon >7)
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
			themVaoDau(l, p); //  Them mot node vao cuoi danh sach
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
		else if (luachon == 5)
		{
			xoaCuoi(l);
		}
		else if (luachon == 6)
		{
			int x;
			cout << "\nNhap note q";
			cin >> x;
			NODE* q = khoiTaoNode(x);
			xoaSauNodeq(l, q);
		}
		else if (luachon == 7)
		{
			quickSort(l);
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