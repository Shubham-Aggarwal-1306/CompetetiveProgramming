#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int currDepth = 0;

        for (char i : s) {
            if (i == '(') {
                currDepth++;
                maxi = max(currDepth, maxi);
            }
            if (i == ')')
                currDepth--;
        }
        return maxi;
    }
};