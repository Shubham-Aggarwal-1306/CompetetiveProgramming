#include <bits/stdc++.h>

using namespace std;

int func(int n, int m, int mid) {
  cout << "Checking for " << mid << endl;
  long long ans = 1;
  long long expo = n;
  long long base = mid;
  while (expo > 0) {
    if (expo % 2) {
      expo--;
      ans = ans * base;
    } else {
      expo /= 2;
      base = base * base;
    }
    cout << "ans: " << ans << " expo: " << expo << " base: " << base << endl;
    if (ans > m)
      return 2;
  }
  if (ans == m)
    return 1;
  else if (ans > m)
    return 2;
  else
    return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 0, high = m;
  while (low <= high) {
    int mid = (low + high) / 2;
    int choice = func(n, m, mid);
    cout << choice << endl;
    if (choice == 2)
      high = mid - 1;
    else if (choice == 1)
      return mid;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  int n = 9, m = 1953125;
  cout << NthRoot(n, m);
  return 0;
}