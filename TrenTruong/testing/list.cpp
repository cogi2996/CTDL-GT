#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct SINHVIEN {
int ID;
float DIEM;
SINHVIEN* next;
int RANK =0;
int SUIT;
char NAME[255];
};

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
     Y->next = nullptr;
    if(Head == nullptr&&K==0)
    {
      //  printf("here%d",Y->RANK);
        Tail = Head = Y;
    }
    if(Head->next ==nullptr&&K==1){
        Head->next = Y;
        Tail = Y;
    }
    int i =0;

	for(SINHVIEN *x = Head; x != nullptr; x = x ->next)
	{

		if(i++ == K  ) // Tìm th?y q nè
		{
            //printf("here");
			SINHVIEN *g = x ->next;
			Y->next = g;
			x ->next = Y;
			return true; // K?t thúc
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
        SINHVIEN *temp;
        sbegin->next  = sv->next;
        temp->RANK  = sv->RANK;// sao chep noi dung y chang , tru dia chi ko sao chep
        delete  sv;
        return temp;
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
return  nullptr;
}
/************************
hàm đếm số lượng node trong LIST
*************************/
int countElement() {
// your code here
    int count =0;
    SINHVIEN *sbegin = Head->next; 
        printf("%d,",sbegin->RANK);
    
    while(sbegin!=nullptr){
        count++;
        sbegin= sbegin->next;
    }
    return count;
// end your code
}
/************************
hàm tách các phần tử âm trong LIST sang 1 LIST mới
*************************/
//LIST getNegative() {
//// your code here
//
//// end your code
//}
//
};

int main(){
    LIST list;
    list.init();
	SINHVIEN *C1; 
	C1 = (SINHVIEN*)malloc(sizeof(SINHVIEN)); 
	C1->RANK = 1;
	list.insert(C1,0);
	printf("%d,,",list.deleteElement(1));
	//printf("%d,",list.insert(C1,0));
   
    C1->RANK = 3;
	list.insert(C1,0);

    C1->RANK = 2;
	list.insert(C1,0);
     int x = C1->RANK;
   //printf return 0;
   //printf list.Tail->next=nullptr;
   //printf SINHVIEN *temp = list.Head->next;
   //printf if(list.Tail->next!=nullptr){
   //printf     printf("here");
   //printf     return 0;
   //printf }

    return 0;
    
 //   printf("\n\n%d",list.xoaCuoi()->RANK);
  // printf("\n\n");
  // int  i =0;
  // for(SINHVIEN *k = list.Front;k!=NULL;k= k->next){
  //   // if(i++==100)
  //   //      break;
  //   i++;
  //   
  //    printf("%d,",list.xoaCuoi()->RANK);
  //}
  //printf("(%d)",i);
  // //xuat(list);
  // 
      
   
    
}