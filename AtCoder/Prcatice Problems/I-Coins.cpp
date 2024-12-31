#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long double probability[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> probability[i];

    long double dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) // index of coins
    {
        dp[i][0] = dp[i - 1][0] * (1 - probability[i]);
        for (int j = 1; j <= n; j++) // count of heads
        {
            dp[i][j] = ((dp[i - 1][j - 1] * probability[i]) + dp[i - 1][j] * (1 - probability[i]));
        }
    }

    long double moreProbability = 0.0;
    for (int j = (n + 1) / 2; j <= n; j++)
    {
        moreProbability += dp[n][j];
    }
    cout << setprecision(10) << moreProbability << endl;
}