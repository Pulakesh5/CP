#include <bits/stdc++.h>
using namespace std;

#define int long long

const long long MOD = 1e9 + 7;

// ll findCount(int n, ll TARGET, vector<vector<ll>> &dp)
// {
//     if (n <= 0)
//     {
//         return (TARGET == 0);
//     }
//     if (TARGET < 0)
//         return 0;
//     if (dp[n][TARGET] != -1)
//         return dp[n][TARGET];
//     ll pick = findCount(n - 1, TARGET - n, dp);
//     ll notPick = findCount(n - 1, TARGET, dp);
//     // cout << n << " " << TARGET << " : " << pick << " " << notPick << endl;
//     return dp[n][TARGET] = (pick + notPick) % MOD;
// }

int32_t main()
{
    int n;
    cin >> n;
    int SUM = 1ll * (n * (n + 1)) / 2;
    if (SUM % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int TARGET = SUM / 2;
    vector<vector<int>> dp(n, vector<int>(TARGET + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= TARGET; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0)
            {
                (dp[i][j] += dp[i - 1][left]) %= MOD;
            }
        }
    }
    cout << dp[n - 1][TARGET] << endl;
    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = 1;
    // cout << findCount(n - 1, TARGET - n, dp);
}