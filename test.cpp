#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long long reverse = 0;
    while (x != 0)
    {
        int temp = x % 10;
        reverse = reverse * 10 + temp;
        if (reverse < -2147483648 || reverse > 2147483648)
            return 0;
        x /= 10;
    }
    return int(reverse);
}

int main()
{
    int x = -1534;
    cout << reverse(x);
    return 0;
}