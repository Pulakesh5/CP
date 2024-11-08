#include <bits/stdc++.h>

using namespace std;
int weight[101], value[101];
vector<long long> dp(100001, INT_MAX);
int N, W;
int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> weight[i] >> value[i];

    int totalValue = 0;
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        totalValue += value[i];
        for (int j = totalValue; j >= value[i]; j--)
        {
            dp[j] = min(dp[j - value[i]] + weight[i], dp[j]);
        }
    }

    for (int i = totalValue; i >= 0; i--)
    {
        if (dp[i] <= W)
        {
            cout << i;
            return 0;
        }
    }
}