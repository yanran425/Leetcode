#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		for (vector<char>::iterator it = letters.begin(); it != letters.end(); it++) {
			if (*it > target) {
				return *it;
			}
		}
		return letters[0];
	}
};

int main() {
	vector<char> v = { 'c','f','j' };
	Solution s;
	cout << s.nextGreatestLetter(v, 'a') << endl;
	return 0;
}