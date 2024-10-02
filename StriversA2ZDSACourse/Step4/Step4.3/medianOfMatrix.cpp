//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperBound(vector<int> &matrix, int x) {
        int n = matrix.size();
        int cnt = n;
        int low = 0, high = n-1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid] > x) {
                cnt = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return cnt;
    }
    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int mid) {
        int count = 0;
        
        for (int i=0; i<m; i++) {
            count+=upperBound(matrix[i], mid);
        }
        
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int m = matrix.size(), n = matrix[0].size();
        
        int low = INT_MAX, high = INT_MIN;
        
        for (int i=0; i<m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
        }
        
        int req = (n * m) / 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, m, n, mid);
            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};
