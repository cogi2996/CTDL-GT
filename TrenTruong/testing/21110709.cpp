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
            int size = 0;
            for(int i = 0;i<=255;i++){
                if((p->USERNAME[i] <='z'&&p->USERNAME[i] >='a')||(p->USERNAME[i] <='Z'&&p->USERNAME[i] >='A'))
                {
                    temp->USERNAME[size++] = p->USERNAME[i];  
                }
            }
            temp->USERNAME[size] = '\0';
            
            //strcpy(a, p->USERNAME);
            LeftMost = LeftMost->next;
            LeftMost->prev = nullptr;
            delete p;
            return temp;
        }
        for(NHANVIEN *k = LeftMost;k!=nullptr;k = k->next){
            if(k->next == RightMost){
                NHANVIEN *temp ,*p = RightMost;
                temp->ID = RightMost->ID;
                temp->LUONG = RightMost->LUONG;
                int size = 0;
                 for(int i = 0;i<=255;i++){
                    if((p->USERNAME[i] <='z'&&p->USERNAME[i] >='a')||(p->USERNAME[i] <='Z'&&p->USERNAME[i] >='A'))
                    {
                        temp->USERNAME[size++] = p->USERNAME[i];  
                    }
                }
                temp->USERNAME[size] = '\0';

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

struct LIST 
{ 
NHANVIEN* Head; 
 NHANVIEN* Tail; 
void init() { 
Head = nullptr; 
 Tail = nullptr; 
} 
 /********************************* 
 * chèn phần tử vào vị trí thứ K của danh sách 
 **********************************/ 
bool insert(NHANVIEN * Y, int K)  
{ 
// your code here 
    Y->next = nullptr;
    if(Head == nullptr&&K==0)
    {
      //  printf("here%d",Y->RANK);
        Tail = Head = Y;
        return true;
    }
    if(Head->next ==nullptr&&K==1){
        Head->next = Y;
        Tail = Y;
        return true;
    }
    int i =0;

	for(NHANVIEN *x = Head; x != nullptr; x = x ->next)
	{

		if(i++ == K  ) 
		{
			NHANVIEN *g = x ->next;
			Y->next = g;
			x ->next = Y;
			return true;
		}
	}
    return false;
 // end your code 
} 
 // kiểm tra danh sách rỗng  
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
NHANVIEN* deleteElement(int K) { 
 // your code here 
 int i =0 ;
NHANVIEN *sbegin = Head;
while(sbegin!=nullptr) {
    if(++i==K)
    {
        NHANVIEN *sv = sbegin->next;
        NHANVIEN *temp;
        sbegin->next  = sv->next;
        int size = 0;
            for(int i = 0;i<=255;i++){
                if((sv->USERNAME[i] <='z'&&sv->USERNAME[i] >='a')||(sv->USERNAME[i] <='Z'&&sv->USERNAME[i] >='A'))
                {
                    temp->USERNAME[size++] = sv->USERNAME[i];  
                }
            }
            temp->USERNAME[size] = '\0';
        temp->ID  = sv->ID;// sao chep noi dung y chang , tru dia chi ko sao chep
        temp->LUONG = sv->LUONG;
        
        delete  sv;
        return temp;
    }
    sbegin= sbegin->next;
}
return nullptr;
 // end your code 
} 
 /************************ 
 //Hãy hoàn thành hàm xử lý lấy giá trị của LIST tại vị trí thứ K nhưng  không thay đổi nội dung LIST 
 // Nếu LIST rỗng thì trả về nullptr 
 *************************/ 
NHANVIEN* getElement(int K) { 
 // your code here 
   if(Head==nullptr) return nullptr;
    int i = 0;
    NHANVIEN *sbegin = Head;
    while(sbegin!=nullptr){
        if(i++==K)
            return sbegin;
        sbegin = sbegin->next;
    }
    return nullptr;
 // end your code 
 } 
 
 /************************ 
 hàm đếm số lượng node trong LIST 
 *************************/ 
int countElement() { 
 // your code here 
    int count =0;
    NHANVIEN *sbegin = Head; 
    while(sbegin!=nullptr){
        count++;
        sbegin= sbegin->next;
    }
    return count;
 // end your code 
 } 
 /************************ 
 hàm tách các phần tử có lương >=1000 trong LIST sang 1 LIST mới  *************************/ 
LIST getNegative() { 
 // your code here 
 LIST list;
 list.init();
 for(NHANVIEN *k = Head; k != nullptr; k = k->next){
    if(k->LUONG >=1000){
        if (list.Head == NULL)
        {

        	list.Head = list.Tail = k; // node dau cung chinh la node cuoi va la p
        }
        else
        {
        	list.Tail->next = k; 
            list.Tail = k;
        }
    }
 }
 return list;
 // end your code 
 } 
};



