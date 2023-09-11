#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&a, int left, int mid, int right) {
    int cnt = 0;
    vector<int> l;
    vector<int> r;
    for (int i=left; i<=mid; i++) l.push_back(a[i]);
    l.push_back(INT_MAX);
    for (int i=mid+1; i<=right; i++) r.push_back(a[i]);
    r.push_back(INT_MAX);
    int i = 0;
    int j = 0;
    int k = left;
    while(k<=right) {
        int temp = a[i];
        if (l[i]<=r[j]) {
            a[k] = l[i];
            i++;
            k++;
        } else {
            a[k] = r[j];
            j++;
            k++;
            cnt += (mid-i-left+1);
        }
    }
    return cnt;
}

int mergeSort(vector<int>&a, int left, int right) {
    int cnt = 0;
    if (left>=right) {
        return cnt;
    }

    int mid = (left + right)/2;
    cnt+=mergeSort(a, left, mid);
    cnt+=mergeSort(a,mid+1, right);
    cnt+=merge(a, left, mid, right);
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int cnt = mergeSort(a, 0, n-1);
    return cnt;
}