#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
void sumArray(int N, int& step) {
	int r = 0;
	
	step += 2;
	for (int i = 1; i <= N; i++)
	{
		step += 3;
		for (int j = 1; j <= i; j++) 
        {
			step += 3;
			for (int k = j; k <= i + j; k++) 
            {
				r = r + 1;
				step += 3;
			}
		}
	}
}
int main() {
	FILE* f;
	fopen_s(&f, "results2.csv", "wt");
	int N = 0;
	while (N < 1000) {
		int step = 0;
		sumArray(N++, step);
		fprintf(f, "%d\n", step);
		printf("%d\n", N);
	}
	fclose(f);
	return 0;
}
