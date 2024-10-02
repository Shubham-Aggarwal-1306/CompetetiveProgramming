#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int t = m * n;

        int low = 0, high = t - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (matrix[mid/n][mid%n] > target) {
                high = mid - 1;
            } else if (matrix[mid/n][mid%n] < target){
                low = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};