#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct SINHVIEN {
int ID;
float DIEM;
SINHVIEN* next;
int RANK;
int SUIT;
char NAME[255];
};
struct LINKEDSTACK
{
SINHVIEN* top;
void init() {
top = nullptr;
}
bool insert(SINHVIEN* Y)
{
if (top == nullptr) {
top = Y;
top->next = nullptr;
return true;
}
Y->next = top;
top = Y;
return true;
}
bool isEmpty()
{
return top == nullptr;
}
SINHVIEN* deleteStack() {
    if (this->isEmpty()) return nullptr;
    SINHVIEN* result;
    result = (SINHVIEN*)calloc(1, sizeof(SINHVIEN));
    result->RANK = top->RANK;result->SUIT = top->SUIT;
    SINHVIEN* next = top->next;
    delete(top);
    top = next;
    return result;
}
/************************
//Hãy hoàn thành hàm xử lý lấy giá trị của STACK nhưng không thay đổi
nội dung STACK
// Nếu STACK rỗng thì trả về nullptr
*************************/
SINHVIEN * getTop() {
// your code here
if(isEmpty()) return nullptr;
else
{
    SINHVIEN *s = this->top;
    return s;

}

// end your code
}
};

/**************************
* Xâu dựng cấu trúc dữ liệu Queue theo template
* giá trị trả về của phương thức giống với STACK
***************************/
struct QUEUE
{
SINHVIEN* Front;
SINHVIEN* Rear;
void init() {
Front = nullptr;
Rear = nullptr;
}
bool insert(SINHVIEN* Y)
{
// your code here
    if(!isEmpty()){
        Front = Rear = Y;
    }
    else{
        Y->next = Front;
        Front = Y;
    }
// end your code
}
bool isEmpty()
{
// your code here
    if(Front == nullptr) return true;
    return false;
// end your code
}
SINHVIEN* deleteQUEUE() {
// your code here
    if(isEmpty()) return nullptr;
    SINHVIEN *s = Front;
    Front= Front->next;
    delete s; 
// end your code
}
/************************
//Hãy hoàn thành hàm xử lý lấy giá trị của QUEUE nhưng không thay đổi
nội dung QUEUE
// Nếu QUEUE rỗng thì trả về nullptr
*************************/
SINHVIEN * getTop() {
// your code here
    if(isEmpty()) return nullptr;
    return Front;
// end your code
}
};
/**************************
* Xâu dựng cấu trúc dữ liệu DeQue theo template
* giá trị trả về của phương thức giống với STACK
***************************/
struct DEQUE
{
SINHVIEN* LeftMost;

SINHVIEN* RightMost;
void init() {
LeftMost = nullptr;
RightMost = nullptr;
}
bool insert(SINHVIEN* Y)
{
// your code here
    if(LeftMost == nullptr)
        LeftMost = RightMost = Y;
    else   
    {
        Y->next = LeftMost;
        LeftMost-> = Y;

    }
// end your code
}
bool isEmpty()
{
// your code here
    
// end your code
}
SINHVIEN* deleteQUEUE() {
// your code here
// end your code
}
/************************
//Hãy hoàn thành hàm xử lý lấy giá trị của DEQUE nhưng không thay đổi
nội dung DEQUE
// Nếu DEQUE rỗng thì trả về nullptr
* left=true thì lấy giá trị từ bên trái
* left=false thì lấy giá trị từ bên phải
*************************/
SINHVIEN * getValue(bool left) {
// your code here
// end your code
}
};
/**************************
* Xâu dựng cấu trúc dữ liệu Danh sách liên kết đơn theo template
* giá trị trả về của phương thức giống với STACK
***************************/
struct LIST
{
SINHVIEN* Head;
SINHVIEN* Tail;
void init() {
Head = nullptr;
Tail = nullptr;
}
/*********************************
* chèn phần tử vào vị trí thứ K của danh sách
**********************************/
bool insert(SINHVIEN* Y, int K)
{

// your code here
    if(Head->next == nullptr&&K == 0)
    {
        if(Head == nullptr)
        {
            Head = Tail = Y;
            return true;
        }    
            
        else{
            Y->next = Head;
            Head = Y;
            return true;
        }
    }
    else{
        int i = 0;
        SINHVIEN *sbegin = Head;
        while(sbegin!=nullptr){
            if(i++==K){
                SINHVIEN *stemp = sbegin->next;
                Y = stemp;
                sbegin->next = Y;
                return true;
            }
            sbegin = sbegin->next;
        }

    }
    return false;

// end your code
}
bool isEmpty()
{
// your code here
    if(Head == nullptr) return true;
    return false;

// end your code
}
/*********************************
* xóa phần tử tại vị trí thứ K của danh sách
**********************************/
SINHVIEN* deleteElement(int K) {
// your code here
int i =0 ;
SINHVIEN *sbegin = Head;
while(sbegin!=nullptr) {
    if(++i==K)
    {
        SINHVIEN *sv = sbegin->next;
        sbegin->next  = sv->next;
        return sv;
        delete sv;
    }
    sbegin= sbegin->next;
}
return nullptr;
// end your code
}
/************************
//Hãy hoàn thành hàm xử lý lấy giá trị của LIST tại vị trí thứ K nhưng
không thay đổi nội dung LIST
// Nếu LIST rỗng thì trả về nullptr
*************************/
SINHVIEN * getElement(int K) {
// your code here
    if(isEmpty()) return nullptr;
    int i = 0;
    SINHVIEN *sbegin = Head;
    while(sbegin!=nullptr){
        if(i++==K)
            return sbegin;
        sbegin = sbegin->next;
    }
    return nullptr;
// end your code
}
/************************
//Hãy hoàn thành tìm vị trí node đầu tiên của LIST có giá trị M nhưng
không thay đổi nội dung LIST
// Nếu LIST rỗng hoặc giá trị không tồn tại thì trả về nullptr
*************************/
SINHVIEN * searchElement(int K) {
// your code here
    // giá trị M là giá trị nào :'))
// end your code
}
/************************
hàm đếm số lượng node trong LIST
*************************/
int countElement() {
// your code here
    int count =0;
    SINHVIEN *sbegin = Head; 
    while(sbegin!=nullptr){
        count++;
    }
    return count;
// end your code
}
/************************
hàm tách các phần tử âm trong LIST sang 1 LIST mới
*************************/
LIST getNegative() {
// your code here

// end your code
}

};