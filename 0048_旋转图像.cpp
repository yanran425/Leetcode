#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - i; j++)
                swap(matrix[size - j - 1][size - i - 1], matrix[i][j]);
        for (int i = 0; i < size / 2; i++)
            swap(matrix[size - i - 1], matrix[i]);
    }
};