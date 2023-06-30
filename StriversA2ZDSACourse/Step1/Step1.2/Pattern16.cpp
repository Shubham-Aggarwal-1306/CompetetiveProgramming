//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int val = 65;
        for (int i = 0; i < n; i++) {
            for (int j = n - i - 1; j > 0; --j) cout << " ";
            for (int j = 0; j <= i; ++j) cout << char(val + j);
            for (int j = i-1; j >= 0; --j) cout << char(val + j);
            cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends