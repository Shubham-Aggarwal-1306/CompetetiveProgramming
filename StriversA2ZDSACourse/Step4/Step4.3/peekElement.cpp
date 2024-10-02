#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            int maxi = INT_MIN;
            int ind = -1;
            for (int i = 0; i < m; i++)
            {
                if (mat[i][mid] > maxi)
                {
                    maxi = mat[i][mid];
                    ind = i;
                }
            }

            int left = mid - 1 >= 0 ? mat[ind][mid - 1] : -1;
            int right = mid + 1 < n ? mat[ind][mid + 1] : -1;

            if (left < maxi && right < maxi)
                return {ind, mid};
            else if (maxi < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};