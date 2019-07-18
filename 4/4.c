#include<stdio.h>

int abs(int x)
	return (x >= 0 ? x : -x);

int reformat(int *v, int n) {
	int i, firstNeg = n-1, tmp;
	
	while (firstNeg > -1 && v[firstNeg] < 0 ) {
		firstNeg--;	
	}
	if (firstNeg == -1)
		return -1;
	
	i = 0;
	while (i < firstNeg) {
		while (v[i] >= 0 && i < firstNeg)
			i++;
		if (i == firstNeg)
			return i + 1;
		tmp = v[firstNeg];
		v[firstNeg] = v[i];
		v[i++] = v[firstNeg--];	
	}
	return i;
}

int getFirstPosInt(int *v, int n) {
	int nPos, i;
	
	nPos = reformat(v, n);
	if (nPos == -1)
		return 1;
	
	for (i = 0; i < nPos; i++) {
		if (abs(v[i]) < nPos) {
			v[abs(v[i]) - 1] *= -1;
		}
	}
	
	for (i = 0; i < nPos; i++)
		if (v[i] > 0)
			return i+1;
	
	return nPos + 1;
}

int main() {
	int v[] = {3, 4, -1, 1};
	
	getFirstPosInt(v, 4);
	
}