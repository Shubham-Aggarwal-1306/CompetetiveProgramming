// User function template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  int lowerBound(vector<int> &arr) {
      int ans = arr.size();
      
      int low = 0, high = arr.size() - 1;
      
      while (low <= high) {
          int mid = (low + high) / 2;
          
          if (arr[mid] >= 1) {
              ans = mid;
              high = mid - 1;
          } else {
              low = mid + 1;
          }
      }
      return ans;
  }
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int cnt_max = 0;
        int ans = -1;
        for (int i = 0; i<arr.size(); i++) {
            int curr = arr[i].size() - lowerBound(arr[i]);
            if (curr > cnt_max) {
                cnt_max = curr;
                ans = i;
            }
        }
        
        return ans;
    }
};