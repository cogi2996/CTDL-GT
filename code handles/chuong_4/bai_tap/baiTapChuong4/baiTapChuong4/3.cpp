#include <iostream>
#include <string>
using namespace std;

struct BIRTHDAY
{
    int day;
    int month;
    int year;
};

struct SINHVIEN
{
    string name;
    string mssv;
    BIRTHDAY birthDay;
    int point;
};

struct node
{
    SINHVIEN data;
    struct node *pNext;
};

typedef struct node NODE;

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

NODE *initNode(SINHVIEN student)
{
    NODE *p = new NODE;
    p->data = student;
    p->pNext = NULL;
    return p;
}

void addTailList(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

SINHVIEN addSv()
{
    SINHVIEN sv;
    cin.ignore(1);
    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.name);
    cout << "Nhap MSSV: ";
    cin >> sv.mssv;
    cout << "Nhap ngay thang nam sinh: ";
    cin >> sv.birthDay.day >> sv.birthDay.month >> sv.birthDay.year;
    cout << "Nhap diem sinh vien: ";
    cin >> sv.point;
    return sv;
}

void ouputListStudent(LIST &l)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << "--------------------------------" << endl;
        SINHVIEN sv = k->data;
        cout << "Ten: " << sv.name;
        cout << endl
             << "MSSV: " << sv.mssv;
        cout << endl
             << "Ngay sinh: " << sv.birthDay.day << "/" << sv.birthDay.month << "/" << sv.birthDay.year << endl;
        cout << "Diem: " << sv.point << endl;
    }
}

void eraseHeadNode(LIST &l)
{
    if (l.pHead == NULL)
        return;
    NODE *p = l.pHead;
    l.pHead = p->pNext;
    delete p;
}

void eraseTailNode(LIST &l)
{
    if (l.pHead == NULL)
        return;
    if (l.pHead->pNext == NULL)
    {
        eraseHeadNode(l);
        return;
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext = NULL;
            l.pTail = k;
            return;
        }
    }
}
void deleteStudent(LIST &l)
{
    cout << "Nhap MSSV sinh vien can xoa: ";
    string svCode;
    cin.ignore(1);
    getline(cin, svCode);
    //  phan tu can xoa nam dau danh sach ( size = 1)
    if (l.pHead == NULL)
        return;
    if (l.pHead->data.mssv == svCode)
    {
        eraseHeadNode(l);
        return;
    }
    //  phan tu can xoa nam cuoi danh sach ( size = 1)
    if (l.pTail->data.mssv == svCode)
    {
        eraseTailNode(l);
        return;
    }
    NODE *g = new NODE;
    // danh sach can xoa co hai phan tu
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.mssv == svCode)
        {
            g->pNext = k->pNext;
            delete k;
            return;
        }
        g = k;
    }
}

void findStudent(LIST l)
{
    cin.ignore(1);
    cout << "Nhap MSSV: ";
    string mssv;
    getline(cin, mssv);
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data.mssv == mssv)
        {
            cout << endl
                 << "--------------------------------" << endl;
            SINHVIEN sv = k->data;
            cout << "Ten: " << sv.name;
            cout << endl
                 << "MSSV: " << sv.mssv;
            cout << endl
                 << "Ngay sinh: " << sv.birthDay.day << "/" << sv.birthDay.month << "/" << sv.birthDay.year << endl;
            cout << "Diem: " << sv.point << endl;
            return;
        }
    }
}

void editProfileStudent(LIST &l)
{
    cin.ignore(1);
    cout << "Nhap MSSV sinh vien can chinh sua: ";
    string svCode;
    getline(cin, svCode);
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        SINHVIEN sv = k->data;
        if (k->data.mssv == svCode)
        {
            int choice1;
            do
            {
                system("cls");
                cout << endl
                     << "[0]-Thoat chinh sua";
                cout << endl
                     << "[1]-Chinh sua ten";
                cout << endl
                     << "[2]-Chinh sua MSSV";
                cout << endl
                     << "[3]-Chinh sua ngay sinh";
                cout << endl
                     << "[4]-Chinh sua diem thi";

                cout << endl;
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                {
                    cout << endl
                         << "Nhap ten can chinh sua: ";
                    string nameChange;
                    cin.ignore(1);
                    getline(cin, nameChange);
                    sv.name = nameChange;
                    break;
                }
                case 2:
                {
                    cout << endl
                         << "Nhap MSSV can chinh sua: ";
                    string MSSV;
                    cin.ignore(1);
                    getline(cin, MSSV);
                    sv.mssv = MSSV;
                    break;
                }
                case 3:
                {
                    cout << endl
                         << "Nhap ngay sinh can chinh sua: ";
                    cin >> sv.birthDay.day >> sv.birthDay.month >> sv.birthDay.year;
                    break;
                }
                case 4:
                {
                    cout << endl
                         << "Nhap diem thi can chinh sua";
                    cin >> sv.point;
                    break;
                }
                case 0:
                    break;
                }
            } while (choice1);
            k->data = sv;
            return;
        }
    }
}
void Menu(LIST &l)
{
    int choice;
    do
    {
        system("cls");
        cout << "\t\t========MENU========";
        cout << "\n\t[0]-Thoat";
        cout << "\n\t[1]-Them sinh vien vao danh sach";
        cout << "\n\t[2]-Xuat danh sach sinh vien ra man hinh";
        cout << "\n\t[3]-Xoa mot sinh vien";
        cout << "\n\t[4]-Sua thong tin sinh vien";
        cout << "\n\t[5]-Tim sinh vien";
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            SINHVIEN sv = addSv();
            addTailList(l, initNode(sv));
            break;
        }
        case 2:
        {
            ouputListStudent(l);
            system("pause");
            break;
        }
        case 3:
        {
            deleteStudent(l);
            break;
        }
        case 4:
        {
            editProfileStudent(l);
            break;
        }
        case 5:
        {
            findStudent(l);
            system("pause");
            break;

        }
        }
    } while (choice);
}
int main()
{
    LIST listSv;
    initList(listSv);
    Menu(listSv);
}