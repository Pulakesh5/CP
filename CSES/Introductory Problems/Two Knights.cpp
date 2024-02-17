#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{
    int n;
    cin >> n;
    cout << 0 << endl;
    for (int i = 2; i <= n; i++)
    {
        int sq = i * i;
        cout << (sq * (sq - 1)) / 2 - 4 * (i - 1) * (i - 2) << endl;
    }
    return 0;
}