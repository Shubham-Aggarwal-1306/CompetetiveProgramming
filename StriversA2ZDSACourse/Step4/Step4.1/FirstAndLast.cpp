#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here
    int low = 0, high = n - 1, floor = -1, ciel = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            ciel = mid;
            low = mid + 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            floor = mid;
            high = mid - 1;
        }
    }
    return {floor, ciel};
}
