#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;


class Solution {
public:
	int lengthOfLastWord(string s) {
		bool flag = false;
		int number = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == ' ' && flag == true) {
				return number;
			}
			else if (s[i] != ' ') {
				flag = true;
				number++;
			}

		}
		return number;
	}
};

int main() {
	Solution s;
	string str = "luffy is still joyboy";
	int result = s.lengthOfLastWord(str);
	cout << result << endl;
	return 0;
}