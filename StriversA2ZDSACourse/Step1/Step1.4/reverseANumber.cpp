//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        int count = 31;
        long long number = 0;
        while (X>0){
            number = number*2 + X%2;
            X = X/2;
            count--;
        }
        while (count>=0){
            number *=2;
            count--;
        }
        return number;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends