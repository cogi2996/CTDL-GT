#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
void Sum(int N, int& step) {
	int r= 0;
	step += 2;
	for (int i = 1; i <= N - 1; i++)
	{
		step += 3;
		for (int j = i + 1; j <= N; j++) {
			step += 3;
			for (int k = 1; k <= j; k++) {
				r = r + 1;
				step += 3;
			}
		}
	}
}
int main() {
	FILE* f;
	fopen_s(&f, "results1.csv", "wt");
	int N = 0;
	while (N < 100) {
		int step = 0;
		Sum(N++,step);
		fprintf(f, "%d\n", step);
	}
	fclose(f);
	return 0;
}
