#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    int low = 0, high = n, ans = -1;

    while (low<=high){
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
