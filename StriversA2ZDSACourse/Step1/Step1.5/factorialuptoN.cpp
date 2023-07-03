//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> factorials;
    void  fact(long long N, long long i, long long factorial) {
        factorial*=i;
        if (factorial>N) return;
        
        factorials.push_back(factorial);
        fact(N, i+1, factorial);
    }   
    vector<long long> factorialNumbers(long long N)
    {
        fact(N, 1, 1);
        return factorials;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends