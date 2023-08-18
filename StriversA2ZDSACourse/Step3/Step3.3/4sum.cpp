#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> quadArray;
    for (int i=0; i<n; i++) {
        if (i!=0 && nums[i]==nums[i-1]) continue;
        for (int j=1; j<n; j++) {
            if (j!=i+1 && nums[j]==nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while (k<l) {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum>target) {
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    vector<int> quad = {nums[i] , nums[j] , nums[k] , nums[l]};
                    quadArray.push_back(quad);
                    k++;
                    l--;
                    while (k<l && nums[k] == nums[k-1]) k++;
                    while (k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return quadArray;
}