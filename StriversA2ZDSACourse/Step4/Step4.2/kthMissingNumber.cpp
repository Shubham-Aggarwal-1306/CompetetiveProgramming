#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k) {
  // Write your code here.
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    int missing_numbers = vec[mid] - (mid + 1);

    if (missing_numbers < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }

  }
  return k + high + 1;
}
