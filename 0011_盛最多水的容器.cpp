#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int  sum = 0;
		while (left < right) {
			int v = (right - left) * min(height[left], height[right]);
			sum = sum >= v ? sum : v;
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
		}
		return sum;
	}
};

int main() {
	Solution s;
	vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	int res = s.maxArea(v);
	cout << res << endl;;
	return 0;
}
