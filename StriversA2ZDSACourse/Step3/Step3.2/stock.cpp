#include <bits/stdc++.h>

using namespace std;

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int n = prices.size();

    int mini = prices[0];
    int maxi = 0;

    for (int i=1; i<n; i++) {
        int price = prices[i] - mini;
        maxi = max(price, maxi);
        mini = min(prices[i], mini);
    }
    return maxi;
}
