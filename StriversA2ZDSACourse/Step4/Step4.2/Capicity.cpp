#include <bits/stdc++.h>
using namespace std;

long long func(vector<int> &weights, long long maxi) {
    long long days = 1;
    long long curr = 0;
    for (int i: weights) {
        if (curr + i > maxi) {
            days++;
            curr = i;
        } else {
            curr+=i;
        }
    }

    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int mini = *max_element(weights.begin(), weights.end());
    long long low = mini, high = accumulate(weights.begin(), weights.end(), 0);;
    long long ans = 100000 * 500;
    while (low <= high) {
        long long mid = (low + high) /2;
        long long days = func(weights, mid);
        if (days <= d) {
            ans = mid;
            high  = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}