#include <bits/stdc++.h>

using namespace std;
int arr[100005];
long long dp[100005][101];
const long long MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] == 0)
    {
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
    }
    else
        dp[0][arr[0]] = 1;

    int dn[] = {-1, 0, 1};
    for (int i = 1; i < n; i++)
    {
        if (arr[i])
        {
            for (int k = 0; k < 3; k++)
            {
                int nn = arr[i] + dn[k];
                if (nn >= 1 && nn <= m)
                    dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][nn]) % MOD;
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int nn = j + dn[k];
                    if (nn > 0 && nn < (m + 1))
                        dp[i][j] = (dp[i][j] + dp[i - 1][nn]) % MOD;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    long long ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans << endl;
}