#include <iostream>
using namespace std;

struct node
{
    int data;
    node *pNext; // chua dia chi node ke tiep ma con tro tro toi
    node *prev;  // tro toi node truoc no
};

typedef struct node NODE;

NODE *initNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Khong du bo nho de thuc hien hanh dong";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    p->prev = NULL;
    return p;
}

struct list
{
    NODE *pHead;
    NODE *pTail;
};

typedef struct list LIST;

void initList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHeadNode(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->prev = p; // tro nguoc lai
        l.pHead = p;
    }
}

void addTailNode(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->prev = l.pTail;
        l.pTail = p;
    }
}

void addPafterQ(LIST &l, NODE *p)
{
    int x;
    cout << "Nhap gia tri cua node q";
    cin >> x;
    NODE *q = initNode(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        addTailNode(l, p);
    }
    else
    {
        for (NODE *k = l.pHead; k != NULL; k = k->pNext)
        {
            if (q->data == k->data)
            {
                NODE *h = initNode(p->data);
                h->pNext = k->pNext;
                k->pNext->prev = h;
                k->pNext = h;
                h->prev = k;
            }
        }
    }
}

void eraseHead(LIST &l)
{
    if (l.pHead == NULL)
        return;
    NODE *p = l.pHead;
    l.pHead = l.pHead->pNext;
    l.pHead->prev = NULL;
    delete p;
}

void eraseTail(LIST &l)
{
    if (l.pHead == NULL)
        return;
    if (l.pHead->pNext == NULL)
    {
        eraseHead(l);
        return;
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
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

void quick_sort(LIST &l)
{
    LIST l1, l2;
    NODE *pivot, *p; // phan tu cam canh va bien chay
    initList(l1);
    initList(l2);
    if (l.pHead == l.pTail)
        return;
    pivot = l.pHead;    // phan tu thu 1
    p = l.pHead->pNext; // phan tu thu 2  
    while (p != NULL)
    {
        NODE *q = p;
        p = p->pNext;    // phan tu thu 3 cho loop sau
        q->pNext = NULL; // de them vao danh sach moi thi node phai moi do phai tro ve NULL nhu dinh nghia tao 1 node
        q->prev = NULL;
        if (q->data < pivot->data)
            addTailNode(l1, q); // them q vao cuoi list
        else
            addTailNode(l2, q);
    };
    quick_sort(l1);
    quick_sort(l2);
    if (l1.pHead != NULL)
    {
        l.pHead = l1.pHead;
        l1.pTail->pNext = pivot;
        pivot->prev = l1.pTail;
    }
    else
    {
        l.pHead = pivot;
    }
    pivot->pNext = l2.pHead;
    if (l2.pHead != NULL)
    {
        l.pTail = l2.pTail; 
        l2.pHead->prev = pivot;
    }
    else
        l.pTail = pivot; 
}

void outPutList(LIST l)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
}

void Menu(LIST &l)
{
    int choice;
    do
    {
        system("cls");
        cout << endl
             << "[0]-Exit";
        cout << endl
             << "[1]-Them vao dau danh sach";
        cout << endl
             << "[2]-Them vao cuoi danh sach";
        cout << endl
             << "[3]-Them phan tu p truoc phan tu q";
        cout << endl
             << "[4]-Xoa phan tu dau tien";
        cout << endl
             << "[5]-Xoa phan tu cuoi cung";
        cout << endl
             << "[6]-Sap xep lai danh sach";
        cout << endl
             << "[7]-Xuat danh sach";
        cout << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            int x;
            cin >> x;
            addHeadNode(l, initNode(x));
            break;
        }
        case 2:
        {
            int x;
            cin >> x;
            addTailNode(l, initNode(x));
            break;
        }
        case 4:
        {
            eraseHead(l);
            break;
        }
        case 5:
        {
            eraseTail(l);
            break;
        }
        case 6:
        {
            quick_sort(l);
            cout << "here";
            break;
        }
        case 7:
        {
            outPutList(l);
            system("pause");
            break;
        }
        }
    } while (choice);
}

int main()
{
    LIST list;
    initList(list);
    Menu(list);
}