#include <bits/stdc++.h>

using namespace std;

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    int curr = -1;
    vector<int> el;
    for (int i=n-1; i>=0; i--) {
        if (a[i] > curr) {
            curr = a[i];
            el.push_back(a[i]);
        }
    }
    return el;
}