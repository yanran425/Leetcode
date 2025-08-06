#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		vector<string> v(numRows);
		int index = 2 * numRows - 2, num = 0;
		for (int i = 0; i < s.size(); i++) {
			v[num] += s[i];
			if (i % (index) < numRows - 1) {
				num++;
			}
			else {
				num--;
			}
		}
		string res = "";
		for (int i = 0; i < v.size(); i++) {
			res += v[i];
		}
		return res;
	}
};

int main() {
	Solution s;

	string str = "G";
	string res = s.convert(str, 1);
	cout << res << endl;;
	return 0;
}

