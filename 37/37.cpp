//tested on LeetCode

#include<iostream>
#include<vector>

using namespace std;

void getReprezentation(int reprez, vector<int>& x, vector<int>& nums) {
	int i = 0;
	while (reprez != 0) {
		if ((reprez & 1) == 1)
			x.push_back(nums[i]);
		i++;
		reprez = reprez >> 1;
	}
}

void subsets(vector<int>& nums, vector<vector<int>>& out) {
	int count = static_cast<int>(pow(2, nums.size()));
	out.reserve(count);
	for (int i = 0; i < count; i++) {
		vector<int> x;
		getReprezentation(i, x, nums);
		out.push_back(x);
	}
}


int main() {
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> out;
	subsets(nums, out);

	cout << '[';
	for (const vector<int>& elems : out) {
		cout << '[';
		for (const int& i: elems) 
			std::cout << i << ' ';
		cout << "], ";
	}
	getchar();
}