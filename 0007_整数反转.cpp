#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		if (x > 0) {
			string str = to_string(x);
			std::reverse(str.begin(), str.end());
			res = stoll(str);
		}
		else if (x < 0) {
			string str = to_string(x);
			std::reverse(str.begin() + 1, str.end());
			res = stoll(str);
		}
		else {
			return 0;
		}
		if (res > pow(2, 31) - 1 || res < pow(2, 31) * (-1)) {
			return 0;
		}
		else {
			return res;
		}
	}
};

int main() {
	Solution s;
	int res = s.reverse(-123);
	cout << res << endl;
	return 0;
}
