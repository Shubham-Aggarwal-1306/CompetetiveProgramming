#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        int itr = 0;
        while (itr < s.size()) {
            if (s[itr] == 'I') {
                if (itr + 1 < s.size()) {
                    if (s[itr + 1] == 'V') {
                        val += 4;
                        itr += 2;
                        continue;
                    }
                    if (s[itr + 1] == 'X') {
                        val += 9;
                        itr += 2;
                        continue;
                    }
                } 
                val += 1;
            
            } else if (s[itr] == 'V')
                val += 5;
            else if (s[itr] == 'X') {
                if (itr + 1 < s.size()) {
                    if (s[itr + 1] == 'L') {
                        val += 40;
                        itr += 2;
                        continue;
                    }
                    if (s[itr + 1] == 'C') {
                        val += 90;
                        itr += 2;
                        continue;
                    }
                }
                    val += 10;
                
            } else if (s[itr] == 'L')
                val += 50;
            else if (s[itr] == 'C') {
                if (itr + 1 < s.size()) {
                    if (s[itr + 1] == 'D') {
                        val += 400;
                        itr += 2;
                        continue;
                    }
                    if (s[itr + 1] == 'M') {
                        val += 900;
                        itr += 2;
                        continue;
                    }
                }
                val += 100;
            } else if (s[itr] == 'D')
                val += 500;
            else if (s[itr] == 'M')
                val += 1000;
            itr++;
        }
        return val;
    }
};