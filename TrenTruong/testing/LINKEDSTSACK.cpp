#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct ACCOUNT
{
    int ID;
    int DIEM;
    int next;
    char USERNAME[255];
};
struct LINKEDSTACK
{
    int Top = -1;
    void init()
    {
        Top = -1;
    }
    static const int M = 1000;
    ACCOUNT _stack[M];
    bool insert(ACCOUNT Y)
    {
        Top = Top + 1;
        if (Top >= M)
            return false;
        _stack[Top] = Y;
        return true;
    }
    ACCOUNT deleteElement()
    {
        ACCOUNT result;
        result.next = -1;
        if (Top < 0)
        {
            return result;
        }
        result = _stack[Top];
        Top = Top - 1;
        return result;
    }
    bool isEmpty()
    {
        return Top <= -1;
    }
    /************************
    //Hãy hoàn thành hàm xử lý lấy giá trị của STACK nhưng không thay đổi
    nội dung STACK
    // Nếu STACK rỗng thì trả về element có next=-1
    *************************/
   
    ACCOUNT getTop()
    {
        // your code here
        ACCOUNT temp ;

        temp.next = -1;
        if(Top == -1){
            return temp;
        }
        return _stack[Top];
        // end your code
    }
}; /**************************
    * Xâu dựng cấu trúc dữ liệu Queue theo template
    * giá trị trả về của phương thức giống với STACK
    ***************************/
struct QUEUE 
{ 
int Front; 
int Rear; 
        static const int M=1000; 
ACCOUNT _queue[M]; 

void init() { 
Front = -1; 
 Rear = -1; 
} 
bool insert(ACCOUNT Y)  
{ 
// your code here 
    // full
    Y.next = -1;
    if(Rear>=M)
        return false;
    if(Front ==-1) 
        Front = 0;
    Rear++;
    _queue[Rear] = Y;
    return true;
 // end your code 
} 
bool isEmpty() 
{ 
// your code here 
    if(Front == -1) return true;
    return false;
 // end your code 
} 
ACCOUNT deleteQUEUE() { 
 // your code here 

    if(Front == -1 || Front > Rear)
        return;
    else{
        int tempRear = Rear;
        Rear = Rear -1;
        return _queue[tempRear];
    }
    return;
 // end your code 
} 
 /************************ 
 //Hãy hoàn thành hàm xử lý lấy giá trị của QUEUE nhưng không thay đổi  nội dung QUEUE 
 // Nếu QUEUE rỗng thì trả về giá trị có next=-1 
 *************************/ 
ACCOUNT getTop() { 
 // your code here 
 ACCOUNT temp;
 temp.next = -1;
 if(Front == -1){
     return temp;
 }
 else{
     return _queue[Front];
 }
 // end your code 
 } 
}; 
