// tested on LeetCode

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bitsAppearance(32, 0);
		int i, res = 0;

		for (int e : nums)
			for (i = 0; i < 32; i++)
				(e & (1 << i)) != 0 ? bitsAppearance[i]++ : 0;

		for (i = 31; i >= 0; i--)
			res = (res << 1) | (bitsAppearance[i] % 3);

		return res;
	}
};

int main() {
	Solution s;
	vector<int> v = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
	//vector<int> v = { 2, 2, 3, 2 };

	cout << s.singleNumber(v);
	getchar();
}