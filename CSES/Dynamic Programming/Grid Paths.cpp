#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 1));
    char cell;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cell;
            if (cell == '*')
                grid[i][j] = 0;
        }
    }
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    queue<vector<int>> q_cell;
    if (grid[n - 1][n - 1] == 1)
    {
        q_cell.push({n - 1, n - 1});
        dp[n - 1][n - 1] = 1;
        grid[n - 1][n - 1] = -1;
    }
    int dx[] = {0, -1};
    int dy[] = {-1, 0};
    while (!q_cell.empty())
    {
        vector<int> cell = q_cell.front();
        q_cell.pop();
        // cout << cell[0] << " " << cell[1] << " :\n";
        for (int k = 0; k < 2; k++)
        {
            int x = cell[0] + dx[k];
            int y = cell[1] + dy[k];
            if (x >= 0 && y >= 0)
            {
                if (grid[x][y])
                    dp[x][y] = (dp[x][y] + dp[cell[0]][cell[1]]) % MOD;
                // cout << '\t' << x << " " << y << ", " << dp[x][y] << endl;
                if (grid[x][y] == 1)
                {
                    q_cell.push({x, y});
                    grid[x][y] = -1;
                }
            }
        }
    }

    cout << dp[0][0] << endl;
}