#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct SINHVIEN {
	int ID;
	float DIEM;
	SINHVIEN* next;
	char NAME[255];
};
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
		if(LeftMost==nullptr){
			RightMost = Y;
			RightMost->next = nullptr;
			LeftMost = Y;
			LeftMost->next = nullptr;
			return true;
		}
		LeftMost->next = Y;
		LeftMost = Y;
		LeftMost->next=nullptr;
		return 0;
	// end your code	
	}
	bool isEmpty()
	{
	// your code here
		return LeftMost==nullptr;
	// end your code
	}
	SINHVIEN* deleteQUEUE() {
	// your code here
		if (this->isEmpty()) return nullptr;
		SINHVIEN* result;
		result = (SINHVIEN*)calloc(1, sizeof(SINHVIEN));
		result->ID=RightMost->ID;
		SINHVIEN* next = RightMost->next;
		delete(RightMost);
		RightMost = next;
		if(RightMost==nullptr)
			LeftMost = nullptr;
		return result;
	// end your code
	}
	SINHVIEN * getValue(bool left) {
	// your code here
		if(left==true)
			return LeftMost;
		else
			return RightMost;
	// end your code	
	}
};
int main(){
	DEQUE deque;
	deque.init();
	srand(time(NULL));
	printf("Insert:\n");
	SINHVIEN* node;
	for (int i = 0; i < 4; i++) {
		node = (SINHVIEN*)malloc(sizeof(SINHVIEN));
		node->ID = rand();
		deque.insert(node);
		printf("%d\n",node->ID);
	}
	if (deque.isEmpty())
		printf("\nEmpty!\n");
	else
		printf("\nNot Empty!\n");
	while(deque.isEmpty()==false){
		SINHVIEN* node2 = deque.deleteQUEUE();
		printf("%d\n", node2->ID);
	}
	return 0;
}
