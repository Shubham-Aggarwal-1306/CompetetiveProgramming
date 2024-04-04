#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &stalls, int k, int dist) {
  int n = stalls.size();
  int spaces = 1;
  int curr = 0;
  for (int i = 1; i < n; i++) {
    if ((stalls[i] - stalls[curr]) >= dist) {
      spaces++;
      curr = i;
    }
    if (spaces >= k) {
      return 1;
    }
  }
  return 0;
}

int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());

  int maxi = stalls[stalls.size() - 1];
  int mini = stalls[0];

  int low = 1, high = maxi - mini;

  while (low <= high) {
    int mid = (low + high) / 2;
    int isChoice = func(stalls, k, mid);

    if (isChoice) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return high;
}