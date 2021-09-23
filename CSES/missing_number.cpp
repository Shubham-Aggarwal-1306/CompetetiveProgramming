#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll arr[N];
    ll wrong_sum = 0;
    for (ll i=0; i<N-1; i++){
        cin >> arr[i];
        wrong_sum += arr[i];
  }
    ll sum = (N*(N+1))/2;
    cout << (sum - wrong_sum) <<  "\n";
    return 0;
}