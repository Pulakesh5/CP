#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

#define INF 1e18

int mindist[101][101];
int orders[15][2];
int dp[101][5000];

int TotalOrder, N, M, Base;
int FINISHED;
int solve(int currCity, int remainingMask)
{
    // if (remainingMask == FINISHED)
    // {
    //     return mindist[currCity][Base];
    // }

    if (dp[currCity][remainingMask] != -1)
        return dp[currCity][remainingMask];

    int ans = INF, flag = 0;
    for (int i = 0; i < TotalOrder; i++)
    {
        if ((remainingMask & (1 << i)) == 0)
        {
            flag = 1;
            int cost = mindist[currCity][orders[i][0]] + mindist[orders[i][0]][orders[i][1]];
            cost += solve(orders[i][1], remainingMask | (1 << i));

            if (cost < ans)
                ans = cost;
        }
    }
    // cout << currCity << " " << remainingMask << " -> " << ans << endl;

    if (flag == 0)
        return dp[currCity][remainingMask] = mindist[currCity][Base];
    return dp[currCity][remainingMask] = ans;
}
void clear()
{
    for (int i = 1; i <= 100; i++)
    {
        for (int j = i + 1; j <= 100; j++)
        {
            mindist[i][j] = INF;
        }
    }
    for (int i = 1; i <= 100; i++)
        mindist[i][i] = 0;
    memset(orders, 0, sizeof(orders));
    memset(dp, -1, sizeof(dp));
}
void floyd_warshall()
{
    for (int inter = 1; inter <= N; inter++)
    {
        for (int src = 1; src <= N; src++)
        {
            for (int dest = 1; dest <= N; dest++)
            {
                if (mindist[src][dest] > mindist[src][inter] + mindist[inter][dest])
                    mindist[src][dest] = mindist[src][inter] + mindist[inter][dest];
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> M >> Base;

        clear();
        for (int i = 0; i < M; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            mindist[u][v] = min(d, mindist[u][v]);
            mindist[v][u] = min(d, mindist[v][u]);
        }
        floyd_warshall();
        int z, u, v, b;
        cin >> z;

        int orderCount = 0;
        for (int i = 0; i < z; i++)
        {
            cin >> u >> v >> b;
            for (int j = orderCount; j < (orderCount + b); j++)
            {
                orders[j][0] = u;
                orders[j][1] = v;
            }
            orderCount += b;
        }

        TotalOrder = orderCount;
        FINISHED = (1 << orderCount) - 1;
        cout << solve(Base, 0) << endl;
    }
}