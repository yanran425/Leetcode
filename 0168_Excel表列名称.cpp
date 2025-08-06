#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str = "";
        do {
            int yushu = columnNumber % 26;
            if (yushu == 0) {
                yushu = 26;
                columnNumber = columnNumber - 26;
            }
            str = str + char(yushu + 64);
            columnNumber = columnNumber / 26;
        } while (columnNumber > 0);

        reverse(str.begin(), str.end());
        return str;
    }
};


int main() {
    Solution s;
    string res = s.convertToTitle(701);
    cout << res << endl;
    return 0;
}