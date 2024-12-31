#include <bits/stdc++.h>

using namespace std;
int boys[101], girls[101];
int dp[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> boys[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> girls[i];

    sort(boys, boys + n);
    sort(girls, girls + m);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (abs(boys[i - 1] - girls[j - 1]) <= 1)
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            // cout << i << " " << j << " : " << endl;
            // cout << "\t" << dp[i][j] << " " << dp[i - 1][j] << " " << dp[i][j - 1] << ", " << dp[i - 1][j - 1] << endl;
            // cout << '\t' << boys[i] << " " << girls[j] << endl;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][m];
}