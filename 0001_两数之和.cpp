#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					v.push_back(i);
					v.push_back(j);
					return v;
				}
			}
		}
		return v;
	}
};

int main() {
	vector<int> nums;
	Solution s;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	vector<int> v = s.twoSum(nums, 9);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

