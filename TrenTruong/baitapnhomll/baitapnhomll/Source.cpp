#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include<thread>
#include<vector>
#include <algorithm>
#include<time.h>
using namespace std;
vector<int>e1;
vector<int>e2;
/*
7
1 1 1 5	
1 2 2 3
1 3 2 4	
1 4 3 4	
1 5 6 9
0 6 4 1
0 7 3 2
*/
struct people {
    int direc; // huong di
    int order; // thu tu
    int root; // diem xuat phat
    int des; // diem den
    struct people* next;
};

typedef struct people PEOPLE;

struct elevator {
    int state = 2;
    PEOPLE* Front;
    PEOPLE* Rear;

};

typedef struct elevator ELEVATOR;

bool isEmpty(ELEVATOR&l) {
    return l.Front == NULL;
}

void initEle(ELEVATOR& elevator) {
    elevator.Front = NULL;
    elevator.Rear = NULL;
}

PEOPLE* initPeo(PEOPLE peo) {
    PEOPLE* p = new PEOPLE;
    if (p == NULL)
    {
        cout << "\n Khong du bo nho de cap phat";
        return NULL;
    }
    p->direc = peo.direc;
    p->order = peo.order;
    p->root = peo.root;
    p->des = peo.des;
    p->next = NULL;
    return p;
}

void insertPeo(ELEVATOR& ele, PEOPLE* pe)
{
    if (ele.Front == NULL)
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
    if (ele.Front == NULL)
    {
        return;
    }
    PEOPLE* p = ele.Front;
    ele.Front = ele.Front->next;
    delete p;
}

void delePeo(ELEVATOR &l,int x,int direc) {
    if (l.Front ==  NULL)
    {
        return;
    }
    if (l.Front->des == x && l.Front->direc== direc)
    {
        PEOPLE* p = l.Front;
        l.Front = l.Front->next;
        delete p;
        return;
    }
    

    
    for (PEOPLE* k = l.Front; k != NULL; k = k->next)
    {
        if (k->next->des == x && k->next->direc == direc)
        {
            PEOPLE* g = k->next;
            k->next = g->next;
            delete g;
            return;
        }
    }
}

void updated(int state,ELEVATOR &l,int direc)
{
    int keyCheck = 0;
    for (int i = 0; i < e1.size(); i++) {
        if (e1[i] == state)
        {
            keyCheck = 1;
            e1.erase(e1.begin()+i);
            cout << endl; i--;
        }
    }
    if (keyCheck == 1)
    {
        cout << "-->Oppened" << endl;
    }   
    keyCheck = 0;
    for (int i = 0; i < e2.size(); i++)
    {
        if (e2[i] == state)
        {
            keyCheck = 1;
            e2.erase( e2.begin() + i);
            delePeo(l, state,direc);
            cout << endl;
            i--;
        }
    }
    if (keyCheck == 1)
    {
        cout << "-->Arrived" << endl;
    }
}

int main()
{
    ELEVATOR l;
    initEle(l);
    int a[50] = { 0 };
    cout << "Nhap so luong nguoi dung: "<<endl;
    int n;
    cin >> n;
    PEOPLE p[100];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].direc >> p[i].order>>p[i].root >> p[i].des;
    }
     for (int i = 0; i < n; i++)
     {
        insertPeo(l, initPeo(p[i]));
     }
     int FrontDirecTemp = -1;
     a[l.state] = 1;
     /*
     0
     1
     0
     0
     0
     0
     0
     0
     */
     cout << "-------------------" << endl;
     for (int j = 11; j >= 0; j--)
     {
         cout << a[j] << endl;
     }
     a[l.state] = 0;
     cout << "-------------------" << endl;

     while (!isEmpty(l)) {
         if (e2.size() == 0)
         {
             for (PEOPLE* k = l.Front; k != NULL; k = k->next) {
                 if (k->direc == l.Front->direc)
                 {
                     e1.push_back(k->root);
                     e2.push_back(k->des);
                 }
             }
         }
        
         if (l.state < l.Front->root)
         {
             do
             {
                 
                 l.state++;
                 a[l.state] = 1;
                 for (int j = 11; j >= 0; j--)
                 {
                     cout << a[j] << endl;
                 }
                 a[l.state] = 0;
                 Sleep(400);

                 cout << "-------------------" << endl;
             } while (l.state != l.Front->root);
         }
         if (l.state > l.Front->root)
         {

             do {

                 l.state--;
                 a[l.state] = 1;
                 for (int j = 11; j >= 0; j--)
                 {
                     cout << a[j] << endl;
                 }

                 a[l.state] = 0;
                 Sleep(400);

                 cout << "-------------------" << endl;
             } while (l.state != l.Front->root);
         }
         if (l.state == l.Front->root)
         {
             cout << "-->Opened" << endl;
         }
         int destination = l.Front->des;
         int status = 0;
         if (l.state < l.Front->des)
         {
             status = 1;
             do
             {
                 l.state++;
                 a[l.state] = 1;
                 for (int j = 11; j >= 0; j--)
                 {
                     cout << a[j] << endl;
                 }
                 a[l.state] = 0;
                 Sleep(400);

                 cout << "-------------------<<" << endl;
                 updated(l.state, l,l.Front->direc);
              
             } while (l.state != destination);

         }
         if (l.Front == NULL)
         {
             cout << "DONE";
             return 0;
         }
         if (l.state > l.Front->des && status !=1)
         {

             do {

                 l.state--;
                 a[l.state] = 1;
                 for (int j = 11; j >= 0; j--)
                 {
                     cout << a[j] << endl;
                 }

                 a[l.state] = 0;
                 Sleep(400);
                 cout << "-------------------" << endl;
                 updated(l.state, l, l.Front->direc);
             } while (l.state != destination);
         }
         if (e2.size() == 0)
         {
             cout << "-->chuyen trang thai" << endl;
            e1.clear();
            e2.clear();

         }
     }

}












