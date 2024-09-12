#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long sum = 0;
        int i = 0;
        int start = -1;
        int end = -1;
        for (int j =0; j<n; j++) {
            sum+=arr[j];
            while ((sum>s) && (i<=j)) {
                sum-=arr[i];
                i++;
            }
            if (sum==s){
                start = i;
                end = j;
                break;
            }
        }
        if (start!=-1) {
            vector<int> arr2{ start+1, end+1 };
            return arr2;
        } else {
            vector<int> arr2{ -1 };
            return arr2;
        }

    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        cin >> s;
        
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}