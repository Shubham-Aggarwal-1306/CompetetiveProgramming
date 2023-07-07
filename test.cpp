//{ Driver Code Starts
#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
    {
        vector<pair<int,int>> v;
        vector<int> effective_price(n);
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            v.push_back({price[i],magical_price[i]});
        }

        //sort by second element
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
            return (a.first-a.second)>(b.first-b.second);
        });

        //effective price
        for (int i = 0; i < n; i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
            effective_price[i]=v[i].first;
            curr+=v[i].first;
        }
        int i=0;
        while (curr>m && i<n)
        {
            curr= curr - (effective_price[i] - v[i].second);
            effective_price[i]=v[i].second;
            i++;
            cout<<curr<<endl;
        }
        if(curr>m)
        {
            return -1;
        }
        else
        {
            return i;
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
        int n,m;
        cin>>n>>m;
        vector<int>price(n),magical_price(n);
        for(int i=0;i<n;i++)
            cin>>price[i];
        for(int i=0;i<n;i++)
            cin>>magical_price[i];
        Solution ob;
        int ans=ob.minimumMagic(n,m,price,magical_price);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends