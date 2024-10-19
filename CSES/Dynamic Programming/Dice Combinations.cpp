#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int N = max(7, n);
    vector<long long> dp(N + 5);
    const long long MOD = 1e9 + 7;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[1] + dp[2] + 1;
    dp[4] = dp[1] + dp[2] + dp[3] + 1;
    dp[5] = dp[1] + dp[2] + dp[3] + dp[4] + 1;
    dp[6] = dp[1] + dp[2] + dp[3] + dp[4] + dp[5] + 1;
    for (int i = 7; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
            dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
    cout << dp[n] << endl;
}