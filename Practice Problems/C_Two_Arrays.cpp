#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

// int prev[1001][1001], curr[1001][1001];

int main()
{
    int n, m;
    cin >> n >> m;
    // fn(i, ai, bi) ---> fn(i+1, ai, bi) + fn(i+1, ai, bi-1) + fn(i+1, ai+1, bi) + fn(i+1,ai+1, bi-1)
    vector<vector<int>> prev(n + 5, vector<int>(n + 5, 0)), curr(n + 5, vector<int>(n + 5));
    for (int a = 1; a < (n + 1); a++)
    {
        for (int b = a; b < (n + 1); b++)
            prev[a][b] = 1;
    }

    for (int len = 2; len <= m; len++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = n; b >= a; b--)
            {
                // if (b < n)
                prev[a][b] = (prev[a][b] + prev[a][b + 1]) % MOD;
                // if (a - 1 > 0)
                prev[a][b] = (prev[a][b] + prev[a - 1][b]) % MOD;
                // if (a - 1 > 0 && b < n)
                prev[a][b] = (prev[a][b] - prev[a - 1][b + 1] + MOD) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans = (ans + prev[i][j]) % MOD;
        }
    }

    cout << ans << endl;
}