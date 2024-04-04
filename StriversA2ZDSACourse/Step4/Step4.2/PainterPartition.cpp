#include <bits/stdc++.h>

using namespace std;

int noOfArrays(int num, vector<int> a) {
  int sum = 0;
  int n = 1;
  for (auto i : a) {
    if (sum + i > num) {
      sum = i;
      n++;
    } else {
      sum += i;
    }
  }
  return n;
}

int findLargestMinDistance(vector<int> &a, int k)
{
  int low = *max_element(a.begin(), a.end());
  int high = accumulate(a.begin(), a.end(), 0);

  while (low <= high) {
    int mid = (low + high) / 2;
    int s = noOfArrays(mid, a);
    if (s > k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}