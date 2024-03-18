#include <bits/stdc++.h>
using namespace std;

long long findMax(vector<int> &v) {
    int maxi = -1;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int> &v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += (v[i] + hourly - 1) / (hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    long long maxBanana =findMax(v);
    
    int low = 1, high = maxBanana;
    while (low <= high) {                   
        int mid = (low + high) / 2;
            
        long long totalH = calculateTotalHours(v, mid);
   
        if (totalH <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }                                                     
    }
    return low;
}