#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n = a.size();

    long long Sn = (n * (n +1)) / 2;
    long long S2n = (n * (n+1) * (2*n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long) a[i] * (long long) a[i];
    }

    long long val1 = S - Sn; // x - y
    long long val2 = (S2 - S2n) / val1; // x + y;

    long long x = (val1 + val2) / 2;
    long long y = val2 - x;

    return {(int)x, (int)y};


}