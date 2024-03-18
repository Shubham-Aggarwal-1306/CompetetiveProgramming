#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	if (arr.size() == 1)  return arr[0];
	if (arr[0] != arr[1]) return arr[0];
	if (arr[arr.size() - 2] != arr[arr.size() - 1]) return arr[arr.size() - 1];
	// Write your code here
	int low = 1, high = arr.size() - 2;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] != arr[mid + 1] && arr[mid - 1] != arr[mid]) return arr[mid];

		// left side
		if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}