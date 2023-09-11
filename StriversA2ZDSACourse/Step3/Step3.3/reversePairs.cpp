#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &skill, int left, int mid, int right) {
    vector<int> l;
    vector<int> r;
    for (int i=left; i<=mid; i++) l.push_back(skill[i]);
    l.push_back(INT_MAX);
    for (int i=mid+1; i<=right; i++) r.push_back(skill[i]);
    r.push_back(INT_MAX);

    int i = 0;
    int j = 0;
    int k = left;

    while (k<=right) {
        if (l[i] <= r[j]) {
            skill[k] = l[i];
            k++;
            i++;
        } else {
            skill[k] = r[j];
            k++;
            j++;
        }
    }
}

int countPairs(vector<int> &skill, int left, int mid, int right) {
    int cnt = 0;
    int r = mid + 1;
    for (int i = left; i<=mid; i++) {
        while (r<=right && skill[i] > 2 * skill[r] ) r++;
        cnt += (r - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &skill, int left, int right) {
    int cnt = 0;
    if (left >= right) return cnt;
    int mid = (left + right)/2;
    cnt+=mergeSort(skill, left, mid);
    cnt+=mergeSort(skill, mid+1, right);
    cnt+=countPairs(skill, left, mid, right);
    merge(skill, left, mid, right);
    return cnt;
}


int team(vector<int> &skill, int n)
{
    // Write your code here.
    return mergeSort(skill, 0, n-1);
}
