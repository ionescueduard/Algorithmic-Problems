#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int biggestSum(int *v, int n){
	if (n == 1) return v[0] > 0 ? v[0] : 0;
	if (n == 2) return v[0] > v[1] ? (v[0] > 0 ? v[0] : 0) : (v[1] > 0 ? v[1] : 0);
	
	int sum, in, i=1;
	if (v[0] > 0) {
		sum = v[0];
		in = 1;
	} else {
		sum = 0;
		in = 0;
	}
	while (i < n-1) {
		if (in == 0 && v[i] > 0) {
			sum += v[i++];
			in = 1;
			continue;
		}
		
		if (v[i] > 0 && ((v[i+1] > 0 && v[i] >= v[i-1] + v[i+1]) || v[i+1] <= 0 && v[i] >= v[i-1])) {
			in == 1 ? sum -= v[i-1] : 0;
			sum += v[i];
			in = 1;
		} else {
			in = 0;
		}
		i++;
	}
	if (v[i] >= v[i-1] && v[i] > 0) {
		in == 1 ? sum -= v[i-1] : 0; 
		sum += v[i];
	}
	
	return sum;
}

int main() {
	int v1[5] = {2, 4, 6, 2, 5};
	int v2[4] = {5, 1, 1, 5};
	int v3[6] = {5, 5, 5, 5, 5, 5};
	int v4[5] = {5, 5, 5, 5, 5};
	int v5[8] = {2, 4, 6, 2, -5, -2, -3, -5};
	int v6[17] = {-1, 2, 3, -2, -15, -60, 60, 65, -58, 12, 45, 12, 12, 12, 0, 0, 44};
	int v7[2] = {-1, -1};
	int v8[7] = {0, 1, 2, 3, 4, 5, -12};
	int v9[7] = {0, 1, 4, 3, 4, 7, -12};
	
	/*
		{-1, 2, 3, -2, -15, -60, 60, 65, -58, 12, 45, 12, 12, 12, 0, 0, 44}, 16
		{-1, -1}, 0 
		{0, 1, 2, 3, 4, 5, -12}, 9 
		{0, 1, 4, 3, 4, 7, -12}, 11
	*/
	
	printf("%d\n", biggestSum(v1, 5));
	printf("%d\n", biggestSum(v2, 4));
	printf("%d\n", biggestSum(v3, 6));
	printf("%d\n", biggestSum(v4, 5));
	printf("%d\n", biggestSum(v5, 8));
	printf("%d\n", biggestSum(v6, 17));
	printf("%d\n", biggestSum(v7, 2));
	printf("%d\n", biggestSum(v8, 7));
	printf("%d\n", biggestSum(v9, 7));
	
	
}