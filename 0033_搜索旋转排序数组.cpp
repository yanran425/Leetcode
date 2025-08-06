#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		vector<int>::iterator it = find(nums.begin(), nums.end(), target);
		if (it == nums.end()) {
			return -1;
		}
		else {
			int index = it - nums.begin();
			return index;
		}
	}
};

int main() {
	vector<int> v = { 4,5,6,7,0,1,2 };
	Solution s;
	cout << s.search(v, 0) << endl;
	return 0;
}