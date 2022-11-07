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

struct QUEUE
{
SINHVIEN* Front;
SINHVIEN* Rear;
void init() {
Front = NULL;
Rear = NULL;
}
bool insertFront(SINHVIEN* Y) // chen vao dau
{
// your code here
    Y->next =  NULL;// neu khong co init node thi mot node chen them next phai ->null
    if (Front == NULL)
	{
        
		Front = Rear = Y; // node dau cung chinh la node cuoi va la p
        return true;
	}
	else
	{
		Y->next = Front; // cho con tro cua node can them la node p lien ket den node dau - pHead
		Front = Y;  // cap nhat lai pHead chinh la node p 
        return true;
	}
    return false;
// end your code
}

bool insertBehind(SINHVIEN *Y){
     Y->next =  NULL;// neu khong co init node thi mot node chen them next phai ->null
    if (Front == NULL)
	{
        
		Front = Rear = Y; // node dau cung chinh la node cuoi va la p
        return true;
	}
	else
	{
		Rear->next = Y; 
        Rear = Y;
        return true;
	}
    return false;
}
bool isEmpty()
{
// your code here
    if(Front == NULL) return true;
    return false;
// end your code
}
SINHVIEN* xoaDau() {
// your code here
    if(isEmpty()) return NULL;
    SINHVIEN *s = Front,*p;
    Front= Front->next;
    p->RANK = s->RANK;
    delete s; 
    return p;
    
// end your code
}
SINHVIEN *xoaCuoi(){
    if(Front ==NULL) return NULL;
    if(Front->next == NULL)
        return xoaDau();
    for(SINHVIEN *k = Front;k!=NULL;k=k->next)
    {
        if(k->next == Rear)
        {
            SINHVIEN* temp;
            temp = Rear;
            delete Rear;
            k->next = NULL; // cat dut ra thi con tro do co duoi chua dc gan null
            Rear = k; 
            return temp; 
        }
    }
}
/************************
//Hãy hoàn thành hàm xử lý lấy giá trị của QUEUE nhưng không thay đổi
nội dung QUEUE
// Nếu QUEUE rỗng thì trả về nullptr
*************************/
SINHVIEN * getTop() {
// your code here
    if(isEmpty()) return NULL;
    return Front;
// end your code
}
};
/**************************
* Xâu dựng cấu trúc dữ liệu DeQue theo template
* giá trị trả về của phương thức giống với STACK
***************************/
void  xuat (QUEUE list)
{
    
}
int main(){
    QUEUE list;
    list.init();
    srand(time(NULL));
	for(int i = 0;i<100;i++){
		SINHVIEN *C1; 
		C1 = (SINHVIEN*)malloc(sizeof(SINHVIEN)); // cap phat vung nho cho cacrd 1
		// co che cap phat dong , moi con tro duoc tro den vung nho duoc cap phat
		// nhung chau co cơ chế delete vùng nhớ đó, dẫn đến sinh ra rác
		// --> delete vùng nhớ mỗi khi thực hiện thao tác xoá , để thu hòi bộ nhớ không dùng nữa
		C1->RANK = rand();
		list.insertBehind(C1);
		printf("%d,",list.Rear->RANK);
        

	}
    
 //   printf("\n\n%d",list.xoaCuoi()->RANK);
    printf("\n\n");
    int  i =0;
    for(SINHVIEN *k = list.Front;k!=NULL;k= k->next){
      // if(i++==100)
      //      break;
      i++;
      
       printf("%d,",list.xoaDau()->RANK);
   }
   printf("(%d)",i);
    //xuat(list);
    
      
   
    
}