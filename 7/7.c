#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int char2int(char x) {
	return (int)x - 'a';
}

int recursive(char *s, int n, int i, int *mem) {
	if (i == n) {
		return 1;
	}
	if (mem[i] != -1) {
		return mem[i];
	}
	if (char2int(s[i]) <= 2 && i + 1 < n && char2int(s[i + 1]) <= 6) {
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
	char s1[17] = "1111111111111111";
	char s2[18] = "11111111111111111";

	printf("%s  ->  %d\n",s1, numOfWays(s1, strlen(s1)));
	printf("%s  ->  %d\n",s2, numOfWays(s2, strlen(s2)));

	getch();
}

