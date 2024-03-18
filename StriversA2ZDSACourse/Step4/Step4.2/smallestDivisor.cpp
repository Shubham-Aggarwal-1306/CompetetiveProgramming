#include <bits/stdc++.h>
using namespace std;


long long func(vector<int> &arr, int div) {
  long long sum = 0;
  for (int i : arr) {
    sum += ((i + div - 1)/ div);
  }
  return sum;
}

int smallestDivisor(vector<int> &arr, int limit) {
  // Write your code here.
  int maxi = *max_element(arr.begin(), arr.end());
  int low = 1, high = maxi;
  int result = -1;
  while (low <= high) {
    int mid = (low + high) / 2;

    long long ans = func(arr, mid);

    if (ans <= limit) {
      high = mid - 1;
	  result = mid;
    } else {
      low = mid + 1;
    }
  }
  return result;
}