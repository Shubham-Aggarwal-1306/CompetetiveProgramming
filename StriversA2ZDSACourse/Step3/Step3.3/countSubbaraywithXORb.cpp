#include <map>;
#include <vector>;
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int count = 0;
    int n = a.size();
    map<int, int> m;
    int curr = 0;
    for (int i = 0; i<n; i++) {
        curr ^= a[i];
        if (m[curr])
        {
            m[curr]++;
        } else {
            m[curr] = 1;
        }
        if (curr == b) {
            count++;
        }
        if (m[curr ^ b]) {
            count+=m[curr ^ b];
        }
    }

    return count;
}