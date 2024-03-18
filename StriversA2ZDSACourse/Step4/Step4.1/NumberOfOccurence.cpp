#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int low = 0, high = n - 1, floor = -1, ciel = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > x) {
      high = mid - 1;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      ciel = mid;
      low = mid + 1;
    }
  }
  low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > x) {
      high = mid - 1;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      floor = mid;
      high = mid - 1;
    }
  }
  if (ciel == -1 && floor == -1) return 0;
  return ciel - floor + 1 ;
}
