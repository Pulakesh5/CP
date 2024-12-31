
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, overhead;
    cin >> N >> overhead;

    int a[N + 1], b[N + 1];

    for (int i = 1; i < N; i++)
        cin >> a[i];
    for (int i = 1; i < N; i++)
        cin >> b[i];
    // dp[i][0] => at i-floor in stairs
    // dp[i][1] => at i-floor in lift
    int dp[N + 1][2];

    dp[1][0] = 0;
    dp[1][1] = 0;

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + overhead) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i - 1];
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << " : " << dp[i][0] << " " << dp[i][1] << endl;
    // }
    for (int i = 1; i <= N; i++)
        cout << min(dp[i][0], dp[i][1] + overhead) << " ";
}