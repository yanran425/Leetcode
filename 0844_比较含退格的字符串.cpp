#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string s1 = "", t1 = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '#') {
				if (s1.length() != 0) {
					s1.pop_back();
				}
			}
			else {
				s1 += s[i];
			}
		}
		for (int i = 0; i < t.length(); i++) {
			if (t[i] == '#') {
				if (t1.length() != 0) {
					t1.pop_back();
				}
			}
			else {
				t1 += t[i];
			}
		}
		if (s1.compare(t1) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution s;
	string str1 = "ab#c";
	string str2 = "ad#c";
	bool res = s.backspaceCompare(str1, str2);
	cout << res << endl;
	return 0;
}