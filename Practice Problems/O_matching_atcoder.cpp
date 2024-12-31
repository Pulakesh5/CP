#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9 + 7;
vector<vector<int>> dp(21, vector<int>(1 << 21, -1));
int solve(vector<vector<int>> &comp, int index, int mask)
{
    int N = comp.size();
    if (index >= N)
        return (__builtin_popcount(mask) == N);
    if (dp[index][mask] != -1)
        return dp[index][mask];

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (mask & (1 << i) || comp[index][i] == 0)
            continue;
        count = (count + solve(comp, index + 1, mask + (1 << i))) % MOD;
    }
    return dp[index][mask] = count;
}
int32_t main()
{
    int N;
    cin >> N;
    vector<vector<int>> comp(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> comp[i][j];
    }
    cout << solve(comp, 0, 0);
}