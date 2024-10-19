#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<long long> dp(x + 1, 0);
    const long long MOD = 1e9 + 7;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int amount = 1; amount <= x; amount++)
        {
            if (amount >= coins[i])
            {
                dp[amount] += dp[amount - coins[i]];
                dp[amount] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;
}