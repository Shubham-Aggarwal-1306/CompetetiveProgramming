#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start = 0, maxLength = 1;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1; // Adjusted length after expansion
            if (len > maxLength) {
                maxLength = len;
                start =
                    left +
                    1; // Update the starting point of the longest palindrome
            }
        };

        // Try to expand around each character (for both odd and even length
        // palindromes)
        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindromes (single center)
            expandAroundCenter(i, i);
            // Even length palindromes (two centers)
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start,
                        maxLength); // Return the longest palindromic substring
    }
};