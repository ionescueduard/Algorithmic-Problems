//Tested on LeetCode
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		unordered_map<string, int> mem;
		return helper(0, 0, word1, word2, mem);
	}

	int helper(int i, int j, string &word1, string &word2, unordered_map<string, int> &mem) {
		int n = word1.size(), m = word2.size();
		string key = to_string(i) + "-" + to_string(j);
		if (mem.find(key) != mem.end())
			return mem[key];

		if (i == n && j == m) return 0;
		if (i == n) return m - j;
		if (j == m) return n - i;

		if (word1[i] == word2[j]) {
			mem[key] = helper(i + 1, j + 1, word1, word2, mem);
			return mem[key];
		}

		int ins = helper(i, j + 1, word1, word2, mem);
		int del = helper(i + 1, j, word1, word2, mem);
		int rep = helper(i + 1, j + 1, word1, word2, mem);
		int currRez = 1 + min(ins, min(del, rep));

		mem[key] = currRez;
		return currRez;

	}
};