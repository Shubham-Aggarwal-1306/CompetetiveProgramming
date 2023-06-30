//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
            int reverse = 0;
            int num = n;
            int temp;
            while(num>0) {
                temp = num%10;
                reverse = reverse*10 + temp;
                num/=10;
            }
            if (reverse ==n){
                return "Yes";
            } else {
                return "No";
            }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends