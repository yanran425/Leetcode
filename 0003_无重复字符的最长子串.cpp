#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string res = "";
		int length = 0;
		for (int i = 0; i < s.length(); i++) {
			int index = res.find(s[i]);
			if (index < 0) {
				res += s[i];
			}
			else {
				if (index == res.length() - 1) {
					res.clear();
					res += s[i];
				}
				else {
					res = res.substr(index + 1);
					res += s[i];
				}
			}
			length = res.length() > length ? res.length() : length;
		}
		return length;
	}
};

int main() {
	Solution s;
	string v = "bbbbb";
	int res = s.lengthOfLongestSubstring(v);
	cout << res << endl;
	return 0;
}

