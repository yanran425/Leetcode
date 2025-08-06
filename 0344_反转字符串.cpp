#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};


int main() {
	Solution s;
	vector<char> v = { 'h','e','l','l','o' };
	s.reverseString(v);
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}