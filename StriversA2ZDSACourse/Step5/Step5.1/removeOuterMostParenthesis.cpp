#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string tot = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (depth > 0) tot+="(";
                depth++;
            } else {
                depth--;
                if (depth > 0) tot+=")";
            }
        }
        return tot;
    }
};