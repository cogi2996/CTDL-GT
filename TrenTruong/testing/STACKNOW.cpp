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

		if(i++ == K  ) // Tìm th?y q nè
		{
            //printf("here");
			NHANVIEN *g = x ->next;
			Y->next = g;
			x ->next = Y;
			return true; // K?t thúc
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
 int salary = 1000;
 LIST list;
 list.init();
 for(NHANVIEN *k = Head; k != nullptr; k = k->next){
    if(k->LUONG >=1000){
        k->next =  NULL;// neu khong co init node thi mot node chen them next phai ->null
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

