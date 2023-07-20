#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numPair;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            numPair.push_back(make_pair(nums[i], i));
        }
        sort(numPair.begin(), numPair.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        int i = 0;
        int j = n-1;
        while (i<j) {
            if (numPair[i].first + numPair[j].first == target) {
                return {numPair[i].second, numPair[j].second};
            } else if (numPair[i].first + numPair[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
    }
};