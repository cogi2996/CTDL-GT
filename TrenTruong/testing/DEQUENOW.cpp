#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NHANVIEN { 
int ID; 
int LUONG; 
 NHANVIEN* next; 
 NHANVIEN* prev;
char USERNAME[255]; 
}; 
struct DEQUE 
{ 
NHANVIEN* LeftMost; 
 NHANVIEN* RightMost; 
void init() { 
LeftMost = nullptr; 
 RightMost = nullptr; 
} 
  
 /************************ 
 //Hãy hoàn thành hàm xử lý chèn giá trị vào DEQUE 
 * hàm return true nếu thành công 
 * left=true thì chèn giá trị từ bên trái 
 * left=false thì chèn giá trị từ bên phải 
 *************************/ 
bool insert(NHANVIEN * Y, bool left)  
{ 
// your code here 
    Y->next = nullptr;
    Y->prev = nullptr;
    if(left == true){
        if(LeftMost == nullptr){
            LeftMost = RightMost = Y;
            return true;
        }
        else{
            Y->next = LeftMost;
            LeftMost->prev = Y;
            LeftMost = Y;
            return true;
        }
    }
    else{
        if(LeftMost == nullptr){
            LeftMost = RightMost = Y;
            return true;
        }
        else{
           RightMost->next = Y;
           Y->prev = RightMost;
           RightMost = Y;
           return true;
        }

    }
    return false;
 // end your code 
} 
 /********************** 
 *nếu rỗng thì trả về true 
 **********************/ 
bool isEmpty() 
{ 
// your code here 
    if(LeftMost == nullptr)
        return true;
    return false;
 // end your code 
} 
 /************************ 
 //Hãy hoàn thành hàm xử lý lấy giá trị khỏi DEQUE 
 * Nếu DEQUE rỗng thì trả về nullptr 
 * left=true thì lấy giá trị từ bên trái 
 * left=false thì lấy giá trị từ bên phải 
 *************************/ 
NHANVIEN* deleteQUEUE(bool left) { 
 // your code here 
    if(left == true){
        if(LeftMost == nullptr)
            return;
        NHANVIEN*p = LeftMost;
        NHANVIEN *temp;
        temp->ID = p->ID;
        temp->LUONG = p->LUONG;
        char a[255];
        //strcpy(a, p->USERNAME);
        LeftMost = LeftMost->next;
        LeftMost->prev = nullptr;
        delete p;
        return temp;

    }
    else{
        if(LeftMost == nullptr)
            return;
        if(LeftMost->next ==nullptr){
            NHANVIEN*p = LeftMost;
            NHANVIEN *temp;
            temp->ID = p->ID;
            temp->LUONG = p->LUONG;
            char a[255];
            //strcpy(a, p->USERNAME);
            LeftMost = LeftMost->next;
            LeftMost->prev = nullptr;
            delete p;
            return temp;
        }
        for(NHANVIEN *k = LeftMost;k!=nullptr;k = k->next){
            if(k->next == RightMost){
                NHANVIEN *temp ;
                temp->ID = RightMost->ID;
                temp->LUONG = RightMost->LUONG;
                char a[255];
            //strcpy(a, p->USERNAME);
                delete RightMost;
                k->next = NULL;
                RightMost = k;
                return temp;

            }
        }

    }
 // end your code 
} 
 /************************ 
 //Hãy hoàn thành hàm xử lý lấy giá trị của DEQUE nhưng không thay đổi  nội dung DEQUE 
 // Nếu DEQUE rỗng thì trả về nullptr 
 * left=true thì lấy giá trị từ bên trái 
 * left=false thì lấy giá trị từ bên phải 
 *************************/ 
NHANVIEN * getValue(bool left) { 
 // your code here 
    if(LeftMost == nullptr)
        return nullptr;
    if(left==true){
        return LeftMost;
    }
    else{
        return RightMost;
    }
 // end your code 
 }
}; 
