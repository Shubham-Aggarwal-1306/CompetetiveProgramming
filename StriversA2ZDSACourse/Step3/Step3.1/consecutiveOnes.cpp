#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int curr = 0;
        for (auto it:nums) {
            if (it==0){
                m = max(m, curr);
                curr=0;    
            } else {
                curr++;
            }
        }
        m = max(m, curr);
        return m;
    }
};