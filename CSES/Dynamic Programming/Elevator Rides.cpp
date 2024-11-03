#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, CAPACITY;
    cin >> n >> CAPACITY;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int totalSubset = 1 << n;

    vector<pair<int, int>> dp(totalSubset); // dp[i] = {num of rides, weight of last ride}
    dp[0] = {1, 0};
    for (int subset = 1; subset < totalSubset; subset++)
    {
        dp[subset] = {21, 0};
        for (int p = 0; p < n; p++)
        {
            if (subset & (1 << p))
            {
                auto [rides, weight] = dp[subset ^ (1 << p)];
                if (weight + weights[p] > CAPACITY)
                {
                    rides++;
                    weight = min(weight, weights[p]);
                }
                else
                    weight += weights[p];
                dp[subset] = min(dp[subset], {rides, weight});
            }
        }
    }

    cout << dp[totalSubset - 1].first << endl;
}