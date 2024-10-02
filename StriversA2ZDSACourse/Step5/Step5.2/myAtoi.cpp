#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
int myAtoi(string s) {
    int i = 0, sign = 1, result = 0;

    // Step 1: Ignore leading whitespaces
    while (i < s.length() && s[i] == ' ') {
        i++;
    }

    // Step 2: Handle the sign if present
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert the digits and stop at the first non-digit character
    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Step 4: Handle overflow and underflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
};