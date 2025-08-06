#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> v(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			v[(i + k) % nums.size()] = nums[i];
		}
		swap(v, nums);
	}
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(-100);
	nums.push_back(3);
	nums.push_back(99);
	s.rotate(nums, 2);
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}