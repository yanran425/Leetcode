#include<iostream>
#include<string>
#include<stack>

using namespace std;


class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				sta.push(s[i]);
			}
			else if (s[i] == ')') {
				if (!sta.empty() && sta.top() == '(') {
					sta.pop();
				}
				else {
					return false;
				}
			}
			else if (s[i] == ']') {
				if (!sta.empty() && sta.top() == '[') {
					sta.pop();
				}
				else {
					return false;
				}
			}
			else if (s[i] == '}') {
				if (!sta.empty() && sta.top() == '{') {
					sta.pop();
				}
				else {
					return false;
				}
			}
		}
		if (sta.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution s;
	string str = "{[]}";
	bool result = s.isValid(str);
	cout << result << endl;
	return 0;
}