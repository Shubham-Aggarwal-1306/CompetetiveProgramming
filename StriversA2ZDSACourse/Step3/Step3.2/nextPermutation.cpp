#include <bits/stdc++.h>

using namespace std;


vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n = A.size();
    int ind = -1;
    
    for(int i=n-2; i>=0; i--) {
        if (A[i]<A[i+1]) {
            ind = i;
            break;
        }
    }

    if (ind==-1) reverse(A.begin(), A.end());
    else {
        for (int i=n-1; i>ind; i--) {
            if (A[ind] < A[i]) {
                swap(A[ind], A[i]);
                break;
            }
        }
        reverse(A.begin() + ind + 1, A.end());
    }
    return A;
}