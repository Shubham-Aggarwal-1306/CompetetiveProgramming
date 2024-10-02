#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        // Iterate over all possible starting points of substrings
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26,
                             0); // Frequency array for characters 'a' to 'z'

            // For each starting point i, consider all substrings starting from
            // i
            for (int j = i; j < n; ++j) {
                // Increment the frequency of the current character
                freq[s[j] - 'a']++;

                // Find the max and min frequency (excluding 0)
                int maxFreq = 0;
                int minFreq = n; // Set to n since the length of any substring
                                 // cannot exceed n

                for (int k = 0; k < 26; ++k) {
                    if (freq[k] >
                        0) { // Only consider characters that are present
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // Calculate the beauty of the current substring
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};