#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll X[n];
    for (ll i = 0; i<n; i++){
        cin >> X[i];
    }
    ll temp = X[0];
    ll moves =0;
    for (ll i = 1; i<n; i++ ){
        if (X[i]<temp){
            moves += temp - X[i];
        }
        else temp = X[i];
    }
    cout << moves;
    return 0;
}