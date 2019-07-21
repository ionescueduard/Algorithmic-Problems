#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int recursive(char *s, int n, int i, int *mem) {
	if (i == n) return 1;

	if (s[i] == '0') return 0;

	if (mem[i] != -1) return mem[i];

	if (s[i] <= '2' && i + 1 < n && s[i + 1] <= '6') {
		int rez = recursive(s, n, i + 1, mem) + recursive(s, n, i + 2, mem);
		mem[i] = rez;
		return rez;
	}
	int rez = recursive(s, n, i + 1, mem);
	mem[i] = rez;
	return rez;
}

int numOfWays(char *s, int n) {
	int i, rez, *mem;
	
	mem = (int*)malloc(strlen(s) * sizeof(int));
	for (i = 0; i < n; i++) {
		mem[i] = -1;
	}

	rez = recursive(s, n, 0, mem);
	free(mem);
	return rez;
}


int main() {
	char s1[6] = "11111";
	char s2[7] = "261341";
	char s3[7] = "161203";

	printf("%s  ->  %d\n",s1, numOfWays(s1, strlen(s1)));
	printf("%s  ->  %d\n",s2, numOfWays(s2, strlen(s2)));
	printf("%s  ->  %d\n", s3, numOfWays(s3, strlen(s3)));

	getch();
}

