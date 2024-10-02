#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string largestOdd = "";
            // Iterate from the end of the string to the start
    for (int i = num.size() - 1; i >= 0; --i) {
        // Check if the current digit is odd
        if (num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9') {
            // Form the substring from the start to the current position
            string oddSubstring = num.substr(0, i + 1);
            // Compare with the current largest odd substring
            if (oddSubstring > largestOdd) {
                largestOdd = oddSubstring;
            }
        }
    }

    return largestOdd;
    }
};