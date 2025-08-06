#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
	string get_char(char c) {
		string res = "";
		//2 97,98,99
		//3 100,101,102
		//4 103,104,105
		//5 106,107,108
		//6 109,110,111
		//7 112,113,114,115
		//8 116,117,118
		//9 119,120,121,122
		int cint = c - '0';
		if (cint < 7) {
			res = res + char(91 + 3 * cint) + char(92 + 3 * cint) + char(93 + 3 * cint);
		}
		else if (cint == 7) {
			res = "pqrs";
		}
		else if (cint == 8) {
			res = "tuv";
		}
		else {
			res = "wxyz";
		}
		return res;
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) {
			vector <string> vr;
			return vr;
		}

		vector <string> vr(1, "");
		for (string::const_iterator sit = digits.begin(); sit != digits.end(); sit++) {
			string str = this->get_char(*sit);
			int size = str.size();
			vector <string> vr_temp;
			for (vector<string>::const_iterator vit = vr.begin(); vit != vr.end(); vit++) {
				for (int i = 0; i < size; i++) {
					vr_temp.insert(vr_temp.end(), *vit);
				}
			}
			vr = vr_temp;

			int size2 = vr.size();
			for (int i = 0; i < size2; i++) {
				vr[i] = vr[i] + str[i % size];
			}
		}
		return vr;
	}
};


int main() {
	string str = "23";
	Solution s;
	vector<string> v = s.letterCombinations(str);
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}