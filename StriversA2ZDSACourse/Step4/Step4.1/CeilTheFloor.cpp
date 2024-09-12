#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
  // Write your code here.

  int low = 0, high = n - 1, floor = -1, ciel = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (a[mid] > x)
    {
      ciel = a[mid];
      high = mid - 1;
    }
    else if (a[mid] < x)
    {
      floor = a[mid];
      low = mid + 1;
    }
    else
    {
      floor = a[mid];
      ciel = a[mid];
      break;
    }
  }
  return {floor, ciel};
}
