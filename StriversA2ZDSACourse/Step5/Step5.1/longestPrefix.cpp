#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int deep = -1;
        int mn = INT_MAX;
        int len = strs.size();
        for (string s : strs) {
            if (mn > s.size()) {
                mn = s.size();
            }
        }

        for (int i = 0; i < mn; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < len; j++) {
                if (strs[j][i] != ch) {
                    return strs[0].substr(0, deep + 1);
                } 
            }
            deep++;
        }
        return strs[0].substr(0, deep + 1);
    }
};