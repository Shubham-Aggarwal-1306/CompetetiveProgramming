#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for (int i = 1; i<=N; i++) {
        vector<int> ansRow;
        int curr = 1;
        ansRow.push_back(1);
        for (int j = 1; j<i; j++) {
            curr = (curr * (i-j))/j;
            ansRow.push_back(curr);
        }
        ans.push_back(ansRow);
    }
    return ans;
}