#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1) {
			return 0;
		}
		int sum = 0;
		for (int i = 0; i < prices.size() - 1; i++) {
			sum = prices[i] < prices[i + 1] ? sum + prices[i + 1] - prices[i] : sum;
		}
		return sum;
	}
};

int main() {
	Solution s;
	vector<int> v = { 7,6,5,4,3 };
	int result = s.maxProfit(v);
	cout << result << endl;
	return 0;
}