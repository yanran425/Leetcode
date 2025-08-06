#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		string s1 = to_string(x);
		for (int i = 0; i < (s1.size() + 1) / 2; i++) {
			if (s1[i] != s1[s1.size() - i - 1]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	bool result = s.isPalindrome(-121);
	cout << result << endl;
	return 0;
}
