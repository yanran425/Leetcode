#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			nums[0] ^= nums[i];
		}
		return nums[0];
	}
};

int main() {
	Solution s;
	vector<int> nums = { 4, 1,2,1,2 };
	int result = s.singleNumber(nums);
	cout << result << endl;
	return 0;
}