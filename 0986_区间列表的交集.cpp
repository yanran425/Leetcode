#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
		vector<vector<int>> v;
		int firstList_index = 0, secondList_index = 0;
		while (firstList_index < firstList.size() && secondList_index < secondList.size()) {
			int first_start = firstList[firstList_index][0];
			int first_end = firstList[firstList_index][1];
			int second_start = secondList[secondList_index][0];
			int second_end = secondList[secondList_index][1];
			if (first_start > second_start) {
				if (first_start > second_end) {
					secondList_index++;
				}
				else {
					int start = first_start, end = 0;
					if (first_end < second_end) {
						end = first_end;
						firstList_index++;
					}
					else {
						end = second_end;
						secondList_index++;
					}
					v.push_back(vector<int> {start, end});
				}
			}
			else if (first_start < second_start) {
				if (first_end < second_start) {
					firstList_index++;
				}
				else {
					int start = second_start, end = 0;
					if (first_end < second_end) {
						end = first_end;
						firstList_index++;
					}
					else {
						end = second_end;
						secondList_index++;
					}
					v.push_back(vector<int> {start, end});

				}
			}
			else {
				int start = second_start, end = 0;
				if (first_end < second_end) {
					end = first_end;
					firstList_index++;
				}
				else {
					end = second_end;
					secondList_index++;
				}
				v.push_back(vector<int> {start, end});

			}
		}
		return v;
	}
};

int main() {
	Solution s;
	vector<vector<int>> v1 = { {0,2},{5,10},{13,23},{24,25} };
	vector<vector<int>> v2 = { {1,5},{8,12},{15,24},{25,26} };
	vector<vector<int>> res = s.intervalIntersection(v1, v2);
	vector<int> v3 = { 1,2,3,4 };
	for (vector<int> i : res) {
		for (int j : i) {
			cout << j << "\t";
		}
		cout << endl;
	}
	return 0;
}