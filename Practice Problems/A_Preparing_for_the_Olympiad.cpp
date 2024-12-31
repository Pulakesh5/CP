#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        int a[n + 5], b[n + 5], dp[n + 5];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + max(0ll, a[i] - b[i + 1]);
        }
        cout << dp[n - 1] + a[n] << endl;
    }
}