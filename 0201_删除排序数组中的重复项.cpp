#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int left = 0;
		for (int right = 1; right < nums.size(); right++) {
			nums[right] != nums[left] ? (nums[++left] = nums[right]) : NULL;
		}
		return left + 1;
	}
};

int main() {
	Solution s;
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	int result = s.removeDuplicates(v);
	cout << result << endl;
	return 0;
}