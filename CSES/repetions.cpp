#include <iostream>
#include<algorithm>
using namespace std;



int main(){
    string s;
    cin >> s;
    int N = s.length();
    int maximum = 1;
    int temp = 1;
    for (int i=0; i<N-1; i++){
        if (s[i]==s[i+1]){
            temp ++;
            maximum = max(maximum, temp);
        }
        else temp = 1;
    
    }
    cout << maximum << "\n";
    return 0;
}