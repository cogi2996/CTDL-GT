#include<bits/stdc++.h>
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

NODE *intiNode(int x) // tra ve con tro NODE
{
	NODE* p =new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addHeadList(LIST& l, int x)
{
	if (l.pHead == NULL)
	{

	}
}

int main()
{

}