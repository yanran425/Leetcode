#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money = 0;

        vector<int>::iterator it_left = prices.begin();
        vector<int>::iterator it_right = prices.begin() + 1;
        for (; it_left != prices.end() - 1; it_right++) {
            if (it_right == prices.end()) {
                it_left++;
                it_right = it_left;
            }
            else if (*it_right - *it_left <= 0) {
                it_left++;
                it_right = it_left;
            }
            else if (*it_right - *it_left > money) {
                money = *it_right - *it_left;
            }
        }
        return money;
    }
};

int main() {
    vector<int> v = { 2,7,1,11,4 };

    Solution s;
    int res = s.maxProfit(v);
    cout << res << endl;
    return 0;
}