#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct CARD {
	int TAG;
	int SUIT;
	int RANK;
	CARD* next;
	char TITILE[255];
};

struct LINKEDSTACK{ 
	CARD* top;

	// cac ham nay bien doi qua sang queuce , dequece
	void init(){
		top = nullptr; // stack chua co phan tu nao het
	}
	bool insert(CARD *Y){
		if(top == nullptr){
			top = Y; 
			top->next = nullptr ;
			return true;
		}
		Y->next = top;
		top = Y; 
		return true;
	}
	bool isEmpty(){
		return top == 0;
	}
	CARD *deleteStack(){
		if (this->isEmpty()) return nullptr;
		CARD* result;
		result = (CARD*)calloc(1, sizeof(CARD));
		result->RANK = top->RANK;result->SUIT = top->SUIT;
		CARD* next = top->next;
		delete(top);
		top = next;
		return result;
	}
	bool push (CARD *Y){
		if(Y == NULL) return NULL;
		if(isEmpty()){
			top = Y;
			return true;
		} 
		else
		{
			Y->next = top;
			top = Y;
		}
	}
	CARD *pop(){
		if(isEmpty()){return NULL;}
		else{
			CARD *Y;
			Y = top;
			delete top;
			top = Y->next;
			return Y;
		}
	}
	CARD *top(){
		if(isEmpty())	
			return nullptr;
		return top;
	}
};

int main(){
	LINKEDSTACK Stack;
	Stack.init();
	srand(time(NULL));
	for(int i = 0;i<100;i++){
		CARD *C1; 
		C1 = (CARD*)malloc(sizeof(CARD)); // cap phat vung nho cho cacrd 1
		// co che cap phat dong , moi con tro duoc tro den vung nho duoc cap phat
		// nhung chau co cơ chế delete vùng nhớ đó, dẫn đến sinh ra rác
		// --> delete vùng nhớ mỗi khi thực hiện thao tác xoá , để thu hòi bộ nhớ không dùng nữa
		C1->RANK = rand();
		Stack.insert(C1);
		printf("%d,",C1->RANK);

	}
	//printf("\nStack is empty ?%d", Stack.isEmpty());
	//printf("\nValuse of Stack");
	//while(Stack.isEmpty() == false){
	//	CARD* C2 =  Stack.deleteStack();
	//	printf("\n%d",C2->RANK);
	//	
	//}
	//printf("\nStack is empty ?%d", Stack.isEmpty());
	printf("\ndone \n");
	for(int i = 0;i<100;i++){
	//	printf("%d,",i);
		printf("%d,",Stack.pop()->RANK);
		//Stack.pop();
	}
	return 1;

}