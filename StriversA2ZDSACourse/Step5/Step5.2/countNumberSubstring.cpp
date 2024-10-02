#include<bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution
{
  public:
     long long int atMostCount(const string& s, int k) {
        vector<int> freq(26, 0); // Frequency array for 26 lowercase characters
        long long int count = 0;  // To store the number of valid substrings
        int distinctCount = 0;    // To track distinct characters in the current window
        int left = 0;             // Left pointer of the sliding window

        // Iterate with the right pointer of the sliding window
        for (int right = 0; right < s.size(); right++) {
            // If the character is new in the current window, increase distinct count
            if (freq[s[right] - 'a'] == 0) {
                distinctCount++;
            }
            // Increment the frequency of the current character
            freq[s[right] - 'a']++;

            // If distinct characters exceed k, shrink the window from the left
            while (distinctCount > k) {
                freq[s[left] - 'a']--;
                // If a character's frequency drops to 0, we have one less distinct character
                if (freq[s[left] - 'a'] == 0) {
                    distinctCount--;
                }
                left++;  // Shrink the window
            }

            // Number of valid substrings in the current window
            count += (right - left + 1);
        }
        return count;
    }

    // Function to count substrings with exactly k distinct characters
    long long int substrCount(string s, int k) {
        if (k == 0) return 0;  // Edge case: No substrings can have 0 distinct characters
        return atMostCount(s, k) - atMostCount(s, k - 1);
    }
};