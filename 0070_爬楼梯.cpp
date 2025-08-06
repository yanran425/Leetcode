#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v = { 0,1,2 };

        if (n == 1 || n == 2) {
            return v[n];
        }

        for (int i = 3; i <= n; i++) {
            v[i % 3] = (v[(i - 1) % 3] + v[(i - 2) % 3]);
        }
        return v[n % 3];
    }
};

int main() {
    Solution s;
    int res = s.climbStairs(9);
    cout << res << endl;
    return 0;
}