#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = find(nums.begin(), nums.end(), val);
		while (it != nums.end()) {
			nums.erase(it);
			it = find(nums.begin(), nums.end(), val);
		}
		return nums.size();
	}
};


int main() {
	vector<int> v = { 1,0,-1,0,-2,2 };

	Solution s;
	int res = s.removeElement(v, 0);
	cout << res << endl;
	return 0;
}