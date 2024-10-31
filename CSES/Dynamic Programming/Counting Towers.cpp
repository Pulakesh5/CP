#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<long long>> dp(1000005, vector<long long>(2));
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        // dp[i][0] => two 1*1 blocks trying to extend
        // dp[i][1] => 1 1*2 block trying to extend
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i][0] = (4 * dp[i + 1][0] + dp[i + 1][1]) % MOD;
            dp[i][1] = (2 * dp[i + 1][1] + dp[i + 1][0]) % MOD;
        }
        cout << (dp[0][0] + dp[0][1]) % MOD << endl;
    }
}