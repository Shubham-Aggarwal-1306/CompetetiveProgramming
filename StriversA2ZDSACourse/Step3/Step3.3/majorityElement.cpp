#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int el1, el2, count1 = 0, count2 = 0;

	for (int i = 0; i< v.size(); i++){
          if ((count1 == 0) && (v[i] != el2)) {
            el1 = v[i];
            count1 = 1;
          } else if ((count2 == 0) && (el1 != v[i])) {
            el2 = v[i];
            count2 = 1;
          } else if (v[i] == el1) {
            count1++;
          } else if (v[i] == el2) {
            count2++;
          } else {
            count1--;
            count2--;
          }
        }

	vector<int> ls;
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i<v.size(); i++) {
		if (el1==v[i]) cnt1++;
		else if (el2==v[i]) cnt2++;
	}
	int mini = (int)(v.size()/3) + 1;
	
	if (cnt1>= mini) ls.push_back(el1);
	if (cnt2>= mini) ls.push_back(el2);

	sort(ls.begin(), ls.end());

	return ls;
}