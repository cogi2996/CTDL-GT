#include<iostream>
using namespace std;
struct PEOPLE{
    int direc = 0; // huong di
    int order = 0; // thu tu
    int des = 0; // diem den
    PEOPLE * next;
};

PEOPLE* initPeople(PEOPLE x){
    PEOPLE *p = new PEOPLE;
    p->direc = x.direc;
    p->order = x.order;
    p->des = x.des;
    p->next = nullptr;
    return p;
}
struct Queue 
{
    int  D1 = 0;
    int D2 = 0;
    int D3 = 0;
    PEOPLE * Front;
    PEOPLE * Rear;
    void init()
    {
        Front = nullptr;
        Rear = nullptr;
    }
    int insert(PEOPLE x)
    {
        cout<<"here";
        PEOPLE *Y = initPeople(x);
        if(Front = nullptr)
        {
            Front = Rear = Y;
            return true;
        }
        else{
            Rear->next =Y;
            Rear = Y;
            cout<<x.direc;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        return Front == nullptr;
    }
    void deleFront()
    {
        if(isEmpty())
        {
            cout<<"co loi xay ra";
            exit(0);
        }
        PEOPLE *p = Front;
        Front = Front->next;
        delete p;
    }
};

int main()
{
    PEOPLE x[10];
    Queue thangmay;
    thangmay.init();
    for(int i= 0;i<9;i++){
        x[i].direc =i;
        cout<<thangmay.insert(x[i]);
    }
    return 0;
    cout<<thangmay.Rear->direc;
    for(PEOPLE *k = thangmay.Front;k !=nullptr;k = k->next)
    {
        cout<<thangmay.Front->direc;
        thangmay.deleFront();
    }
}