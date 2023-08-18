#include <bits/stdc++.h>

using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    if (n==0) return 0;

    unordered_set<int> st;
    int longest = 1;

    for (auto it:a) {
        st.insert(it);
    }

    for (auto it:st) {

        if (st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}