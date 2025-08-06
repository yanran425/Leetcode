#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v = { {1},{} };
        if (rowIndex == 0) {
            return v[0];
        }
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> v_temp = { 1 };
            int base_row = (i - 1) % 2;
            for (int j = 0; j < v[base_row].size() - 1; j++) {
                v_temp.push_back(v[base_row][j] + v[base_row][j + 1]);
            }
            v_temp.push_back(1);
            v[i % 2] = v_temp;
        }
        return v[rowIndex % 2];
    }
};

int main() {
    Solution s;
    vector<int> res = s.getRow(4);
    for (vector<int>::const_iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}