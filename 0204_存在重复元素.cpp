#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		vector<int>::iterator it = adjacent_find(nums.begin(), nums.end());
		if (it == nums.end()) {
			return false;
		}
		else {
			return true;
		}
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2,3,1 };
	bool result = s.containsDuplicate(nums);
	cout << result << endl;
	return 0;
}