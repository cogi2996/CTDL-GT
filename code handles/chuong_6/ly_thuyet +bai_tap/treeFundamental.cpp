#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;

};
typedef struct node NODE;
typedef NODE* TREE;

void initTree(TREE &t)
{
	t = NULL;
}

// them mot phan tu vao cay
void addItem(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
			addItem(t->pLeft, x);
		else if (t->data < x)
			addItem(t->pRight, x);
	}
}

void outPutTree_NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data<<" ";
		outPutTree_NLR(t->pLeft);
		outPutTree_NLR(t->pRight);
	}
}

void outPutTree_NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		outPutTree_NRL(t->pRight);
		outPutTree_NRL(t->pLeft);
	}
}

void outPutTree_LNR(TREE t)
{
	if (t != NULL)
	{
		outPutTree_LNR(t->pLeft);
		cout << t->data << " ";
		outPutTree_LNR(t->pRight);
	}
}

void outPutTree_RNL(TREE t)
{
	if (t != NULL)
	{
		outPutTree_RNL(t->pRight);
		cout << t->data << " ";
		outPutTree_RNL(t->pLeft);
	}
}

void outPutTree_LRN(TREE t)
{
	if (t != NULL)
	{
		outPutTree_LRN(t->pLeft);
		outPutTree_LRN(t->pRight);
		cout << t->data << " ";
	}
}

void outPutTree_RLN(TREE t)
{
	if (t != NULL)
	{
		outPutTree_RLN(t->pRight);
		outPutTree_RLN(t->pLeft);
		cout << t->data << " ";
	}
}

NODE* findNode(TREE t, int x)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (x < t->data)
			findNode(t->pLeft, x);
		else if (x > t->data)
			findNode(t->pRight, x);
		else // neu tim thay  x = t-> data
			return t;
	}
}

void findNodeLeaves(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft == NULL && t->pRight == NULL)
			cout << t->data<<" ";
		findNodeLeaves(t->pLeft);
		findNodeLeaves(t->pRight); // tuong tu duyet tat ca node qua NLR
	}
}

void findNode_2childs(TREE t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
			cout << t->data << " ";
		findNode_2childs(t->pLeft);
		findNode_2childs(t->pRight); // tuong tu duyet tat ca node qua NLR
	}
}

void findNode_1child(TREE t)
{
	if (t != NULL)
	{
		if ((t->pLeft != NULL && t->pRight == NULL)|| (t->pLeft == NULL && t->pRight != NULL))
			cout << t->data << " ";
		findNode_1child(t->pLeft);
		findNode_1child(t->pRight); // tuong tu duyet tat ca node qua NLR
	}
}

int findMaxNodeMax(TREE t)
{
	if (t->pLeft == NULL && t->pRight == NULL)
		return t->data;
	return findMaxNodeMax(t->pRight);
}

void findTempNode(TREE &X, TREE &Y)
{
	if (Y->pLeft != NULL)
	{
		findTempNode(X, Y->pLeft);
	}
	else // da tim ra duoc dia chi node min nhat cua nhanh phai
	{
		X->data = Y->data;
		X = Y;
		Y = Y->pRight; // nhanh trai nhat, nen pRight chac chan la NULL , y la vi tri min cu thay the bang NULL
		// quan trong la no cho cha cua node the mang co pLeft tro duoc den NULL , neu xoa ma node cha the mang chua tro 
		// den gi thi de gay loi
		// co nghia la
		//----> cho node cha cua node the mang tro den NULL roi moi xoa  node the mang 
	}
}

void eraseNode_1childorLeave(TREE &t,int x)
{
	if (t == NULL)
		return;
	else
	{
		if (x < t->data)
			eraseNode_1childorLeave(t->pLeft, x);
		else if (x > t->data)
			eraseNode_1childorLeave(t->pRight, x);
		else
		{
			NODE* X = t;
			if (t->pLeft == NULL) // co con la nhanh phai
			{
				t = t->pRight;
			}
			else if(t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else // co ca hai nhanh
			{
				NODE* Y = t->pRight;
				findTempNode(X,Y);
			}
				
			delete X; // xoa dia chi cu 
			// tinh chat phai thua nhan , thang cha lien ket voi t, thi t doi dia chi, no van lien ket voi
			// dia chi moi cua thang t
		}
	}
}
void menu(TREE& t)
{
	int choice;
	do {
		system("cls");
		cout << "\n1.Them mot phan tu vao cay";
		cout << "\n2.Xuat cay ra man hinh (NLR)";
		cout << "\n3.Xuat cay ra man hinh (NRL)";
		cout << "\n4.Xuat cay ra man hinh theo thu tu tang dan (LNR)";
		cout << "\n5.Xuat cay ra man hinh theo thu tu giam dan (RNL)";
		cout << "\n6.Xuat cay ra man hinh (LRN)";
		cout << "\n7.Xuat cay ra man hinh (RLN)";
		cout << "\n8.Tim kiem phan tu tren cay";
		cout << "\n9.Xuat ra cac node co mot con";
		cout << "\n10.Xuat ra cac node co hai con";
		cout << "\n11.Xuat ra cac node la";
		cout << "\n12.Tim max node";
		cout << "\n13.Xoa node";
		cout << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				int x;
				cin >> x;
				addItem(t, x);
				break;
			}
			case 2:
			{
				outPutTree_NLR(t);
				system("pause");
				break;
			}
			case 3:
			{
				outPutTree_NRL(t);
				system("pause");
				break;
			}
			case 4:
			{
				outPutTree_LNR(t);
				system("pause");
				break;
			}
			case 5:
			{
				outPutTree_RNL(t);
				system("pause");
				break;
			}
			case 6:
			{
				outPutTree_LRN(t);
				system("pause");
				break;
			}
			case 7:
			{
				outPutTree_RLN(t);
				system("pause");
				break;
			}
			case 8:
			{
				int x;
				cout << "Nhap phan tu can tim kiem";
				cin >> x;
				if (findNode(t, x))
					cout << "Ton tai " << x << " trong cay"<<endl;
				else
					cout << "Khong ton tai " << x << " trong cay"<<endl;
				system("pause");
				break;
			}
			case 9:
			{
				findNode_1child(t);
				system("pause");
				break;
			}
			case 10:
			{
				findNode_2childs(t);
				system("pause");
				break;
			}
			case 11:
			{
				findNodeLeaves(t);
				system("pause");
				break;
			}
			case 12:
			{
				cout << findMaxNodeMax(t) << endl;
				system("pause");
				break;
			}
			case 13:
			{
				int x;
				cout << "Nhap gia tri can xoa";
				cin >> x;
				eraseNode_1childorLeave(t, x);
				break;
			}
		}

	} while (choice);
}
int main()
{
	TREE trees;
	initTree(trees);
	menu(trees);
}
