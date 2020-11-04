//tested on LeetCode

#include<iostream>
#include<vector>

using namespace std;

class AnotherSolution {
public:
	void subsets(vector<int>& nums, vector<vector<int>>& out) {
		int count = static_cast<int>(pow(2, nums.size()));
		out.reserve(count);

		vector<int> inserter;
		out.push_back(inserter);
		helper(-1, nums, inserter, out);
	}

private:
	void helper(int lastIndexAdded, vector<int>& nums, vector<int> inserter, vector<vector<int>>& out) {
		for (int i = lastIndexAdded + 1; i < nums.size(); i++) {
			vector<int> newInserter(inserter);
			newInserter.push_back(nums[i]);
			out.push_back(newInserter);
			helper(i, nums, newInserter, out);
		}
	}
};


class BestSolution {
public:
	void subsets(vector<int>& nums, vector<vector<int>>& out) {
		int count = static_cast<int>(pow(2, nums.size()));
		out.reserve(count);
		for (int i = 0; i < count; i++) {
			vector<int> x;
			getReprezentation(i, x, nums);
			out.push_back(x);
		}
	}

private:
	void getReprezentation(int reprez, vector<int>& x, vector<int>& nums) {
		int i = 0;
		while (reprez != 0) {
			if ((reprez & 1) == 1)
				x.push_back(nums[i]);
			i++;
			reprez = reprez >> 1;
		}
	}
};

int main4() {
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> out;

	BestSolution bs;
	//AnotherSolution as;
	bs.subsets(nums, out);

	cout << '[';
	for (const vector<int>& elems : out) {
		cout << '[';
		for (const int& i: elems) 
			std::cout << i << ' ';
		cout << "], ";
	}
	getchar();
	return 0;
}