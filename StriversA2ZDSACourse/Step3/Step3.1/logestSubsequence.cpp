//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum = 0;
        int i = 0;
        int m = -1;
        int start = -1;
        int end = -1;
        for (int j =0; j<n; j++) {
            sum+=arr[j];
            while ((sum>s) && (i<=j)) {
                sum-=arr[i];
                i++;
            }
            if (sum==s){
                int temp = j - i + 1;
                if (temp>m) {
                    start = i;
                    end = j;
                    m = temp;
                }
            }
        }
        if (m!=-1) {
            vector<int> arr2{ start+1, end+1 };
            return arr2;
        } else {
            vector<int> arr2 {-1};
            return arr2;
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends