#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<string>

using namespace std;

class Solution {
public:
    void cal(int i) {
        string str1 = v[(i - 1) % 2];
        string str2 = "";
        char c = str1[0];
        int number = 0;
        for (string::const_iterator it = str1.begin(); it != str1.end(); it++) {
            if (*it == c) {
                number++;
            }
            else {
                str2 = str2 + to_string(number) + c;
                c = *it;
                number = 1;
            }
        }
        str2 = str2 + to_string(number) + c;
        v[i % 2] = str2;
    }
    string countAndSay(int n) {
        string s = "";
        if (n == 1) {
            return "1";
        }
        for (int i = 2; i <= n; i++) {
            cal(i);
        }
        return v[n % 2];
    }
    vector<string> v = { "0", "1" };
};


int main() {
    Solution s;
    string res = s.countAndSay(4);
    cout << res << endl;
    return 0;
}