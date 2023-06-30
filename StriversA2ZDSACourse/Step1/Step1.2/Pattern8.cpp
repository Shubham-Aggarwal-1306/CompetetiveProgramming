//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1 ; j > i; j--) cout << " ";
            for (int j = (2*i + 1); j > 0 ; j--) cout << "*";
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