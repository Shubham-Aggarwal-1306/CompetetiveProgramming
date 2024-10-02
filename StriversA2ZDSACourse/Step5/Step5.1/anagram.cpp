#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mapper;
        for (char i: s) {
            if (mapper[i]) {
                mapper[i]++;
            } else {
                mapper[i] = 1;
            }
        }

        for (char i: t) {
            if (mapper[i]) {
                if (mapper[i] > 0) {
                    mapper[i]--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};