#include<iostream>
using namespace std;

struct people {
    int direc; // huong di
    int order; // thu tu
    int des; // diem den
    struct people * next;
};

typedef struct people PEOPLE;

struct elevator{
    PEOPLE *Front;
    PEOPLE *Rear;
};

typedef struct elevator ELEVATOR;

void initEle(ELEVATOR& elevator){
    elevator.Front = NULL;
    elevator.Rear = NULL;
}

PEOPLE* initPeo(PEOPLE peo){
    PEOPLE* p = new PEOPLE;
    if(p == NULL)
    {
        cout<<"\n Khong du bo nho de cap phat";
        return NULL;
    }
    p->direc = peo.direc;
    p->order = peo.order;
    p->des = peo.des;
    p->next = NULL;
    return p;
}

void insertPeo(ELEVATOR& ele,PEOPLE *pe)
{
    if(ele.Front = NULL)
    {
        ele.Front = ele.Rear = pe;
    }    
    else
    {
        ele.Rear->next = pe;
        ele.Rear = pe;
    }
}

void deleFront(ELEVATOR& ele)
{
    if(ele.Front == NULL)
    {
        return;
    }
    PEOPLE *p = ele.Front;
    ele.Front = ele.Front->next;
    delete p;
}

int main()
{
    ELEVATOR l;
    initEle(l);
    for(int i= 0;i< 9;i++)
    {
        PEOPLE pe;
        pe.direc = i; 
       insertPeo(l,initPeo(pe));
    }

}












