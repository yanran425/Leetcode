#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> v;
		vector<int>::iterator it = find(nums.begin(), nums.end(), target);
		if (it == nums.end()) {
			v.push_back(-1);
			v.push_back(-1);
		}
		else {
			int index = it - nums.begin(), i = 0;
			v.push_back(index);
			for (; it != nums.end() && *it == target; it++, i++) {}
			v.push_back(index + i - 1);
		}
		return v;
	}
};

int main() {
	vector<int> nums;
	Solution s;
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	vector<int> v = s.searchRange(nums, 8);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
