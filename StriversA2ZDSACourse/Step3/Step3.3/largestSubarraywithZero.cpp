#include<vector>
#include <map>
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
// Write your code here.
    int maxi = 0;
    int sum = 0;
    int n = arr.size();
    map<int, int> m;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            maxi = i + 1; // Length of subarray from the beginning to index i
        } else if (m.find(sum) != m.end()) {
            maxi = max(maxi, i - m[sum]);
        } else {
            m[sum] = i;
        }
    }
    
    return maxi;
}