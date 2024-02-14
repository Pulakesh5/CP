#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    int bitStrings = 1;
    while (n--)
    {
        bitStrings = (bitStrings * 2) % MOD;
    }
    cout << bitStrings << endl;

    return 0;
}