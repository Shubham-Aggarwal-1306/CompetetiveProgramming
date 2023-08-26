#include <bits/stdc++.h>
using namespace std;

void swaper(vector<long long> &a, vector<long long> &b, int i, int j) {
  if (a[i] > b[j]) {
    swap(a[i], b[j]);
  }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b) {
  // Write your code here.
  int n = a.size();
  int m = b.size();
  int len = (n + m);
  int gap = (len / 2) + (len % 2);
  while (gap > 0) {
    int left = 0;
    int right = left + gap;
    while (right < len) {
      if (left < n && right >= n) {
        swaper(a, b, left, right - n);
      } else if (left >= n) {
        swaper(b, b, left - n, right - n);
      } else {
        swaper(a, a, left, right);
      }
	  left++; right++;
    }
    if (gap == 1)
      break;
    gap = (gap / 2) + (gap % 2);
  }
}