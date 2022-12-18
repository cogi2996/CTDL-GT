#include <iostream>
using namespace std;

struct  Record
{
	char data;
	int key;
};

void printRecordKey(Record M[], int N) {
	printf("\n");
	for (int i = 0;i < N;i++) {
		printf("%d ", M[i].key);
	}
}

void InsertionSort(Record M[], int N) {
	int i, j;
	Record R;
	int K;
	for (j = 1;j < N;j++) {
		i = j - 1;
		K = M[j].key;
		R = M[j];
		printRecordKey(M, N);
		while (i >= 0) {
			
			if (K >= M[i].key) {
				M[i + 1] = R;
				break;
			}
			M[i + 1] = M[i];
			i = i - 1;
		}
		
	}
	printRecordKey(M, N);

}

void ComparisionCounting(Record M[], int N) {
	int* COUNT = (int*)malloc(sizeof(int));
	int i,j;
	for (i = 0;i < N;i++) {
		COUNT[i] = 0;
	}
	for (i = N - 1;i >= 1;i--) {
		for (j = i - 1;j >= 0;j--) {
			if (M[i].key <= M[j].key)   
				COUNT[j] += 1;
			else   
				COUNT[i] += 1;
		}
	}
	for (i = 0;i < N;i++) {
		printf("%d ", M[COUNT[i]].key);
	}
}

int main() {
	Record MANG[5];
	MANG[0].key = 1;MANG[1].key = 10;
	MANG[2].key = 5;MANG[3].key = 3;
	MANG[4].key = 2;
	InsertionSort(MANG, 5);
	return 1;
}