#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<string> v;
		string::iterator start = s.begin();
		for (string::iterator it = s.begin(); it != s.end(); it++) {
			if ((*it) == ' ') {
				reverse(start, it);
				start = (++it)--;
			}
		}
		reverse(start, s.end());
		return s;
	}
};


int main() {
	Solution s;
	string v = "Let's take LeetCode contest";
	string res = s.reverseWords(v);
	cout << res << endl;
	return 0;
}