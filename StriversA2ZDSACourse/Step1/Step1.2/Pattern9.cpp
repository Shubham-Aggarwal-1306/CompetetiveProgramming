//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) cout << " ";
            for (int j = 1; j <= i+1; j++) cout << "* ";
            cout << endl;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1 ; j > i; j--) cout << " ";
            for (int j = i; j >= 0 ; j--) cout << "* ";
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends