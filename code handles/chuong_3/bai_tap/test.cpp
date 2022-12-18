#include <bits/stdc++.h>
using namespace std;
void sizeOfFileIn(ifstream &fileIn, vector<string> &listNumb)
{
    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp, ' ');
        listNumb.push_back(temp);
    }
}

void outPutList(vector<string> listNumb)
{
    for (int i = 0; i < listNumb.size(); i++)
    {
        cout << listNumb[i] << " ";
    }
}

void addItems(vector<string> &listNumb)
{
    cout << "Nhap phan tu muon duoc them vao";
    string addItem;
    cin.ignore(1);
    getline(cin, addItem);
    listNumb.push_back(addItem);
}

void eraseItems(vector<string> &listNumb)
{
    // xoa dua vao vi tri phan tu
    int choice1;

    cout << "[0] - Exit" << endl;
    cout << "[1] - Xoa mot phan tu ";
    cout << endl
         << "[2]  - Xoa mot xau phan tu ";
    cout << endl
         << "--> Nhap lua chon: ";
    cin >> choice1;
    switch (choice1)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
        cout << "Nhap vi tri phan tu can xoa:";
        int posDele;
        cin >> posDele;
        listNumb.erase(listNumb.begin() + posDele);
        break;
    }
    case 2:
    {
        int posStart, posEnd;
        cout << "Nhap vi tri bat dau xoa: ";
        cin >> posStart;
        cout << "Nhap vi tri ket thuc xoa: ";
        cin >> posEnd;
        listNumb.erase(listNumb.begin() + posStart, listNumb.begin() + posEnd);
        break;
    }
    default:
    {
        cout << "Yeu cau khong hop le ";
        exit(0);
    }
    }
}

void putItem(vector<string> &list)
{
    cout << "Nhap vi tri phan tu can fix: ";
    int posErase;
    cin >> posErase;
    cout<<"Nhap noi dung can fix: ";
    string fixContent;
	cin.ignore(1);
	getline(cin,fixContent);
    list[posErase] =  fixContent;
}

// void selection_sort(string &list)
// {
//     int sizeOfList = list.size();
//     for (int i = 0; i < sizeOfList - 1; i++)
//     {
//         for (int j = i + 1; j < sizeOfList; j++)
//         {
//             string x, y;
//             x = list[j];
//             y = list[i];
//             if (stoi(x, 0, 10) < stoi(y, 0, 10))
//             {
//                 swap(list[j], list[i]);
//             }
//         }
//     }
// }

// void insertion_sort(string &list)
// {
//     int sizeOfList = list.size();
//     for(int i = 1;i<sizeOfList;i++)
//     {
//         int key = list[i];
//         int k = -1;
//         for(int j = 0;j<i;j++)
//         {
//             string x ,y;
//             x = key;
//             y =  list[j];
//             if(stoi(x,0,10) < stoi(y,0,10))
//                 k = j;
//         }
//         if(k!=-1)
//         {
//             cout<<"here";
//             for(int j = i-1;j>=k;j--)
//                 list[j+1]  =list[j];
//             list[k] = key;
//         }
//     }
// }

int main()
{
    ifstream fileIn;
    fileIn.open("input_6.txt", ios::in);
    vector<string> listNumb;
    sizeOfFileIn(fileIn, listNumb);
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        // add Item
        case 1:
        {
            addItems(listNumb);
            break;
        }
        // Erase Item
        case 2:
        {
            eraseItems(listNumb);
          
            break;
        }
        // // Put item
        case 3:
        {
            putItem(listNumb);
              outPutList(listNumb);
            break;
        }
            // // Sap xep
            // case 4:
            // {
            //     cout << "nhap lua chon thuat toan sap xep: ";
            //     int choice1;
            //     cin >> choice1;
            //     switch (choice1)
            //     {
            //     case 1:
            //     {
            //         selection_sort(listNumb);
            //         break;
            //     }
            //     case 2:
            //     {
            //         insertion_sort(listNumb);
            //
            //         break;
            //     }
            //     }
            // }
        }
    } while (choice);
    fileIn.close();
}