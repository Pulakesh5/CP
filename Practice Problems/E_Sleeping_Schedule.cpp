#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, H, L, R;
    cin >> N >> H >> L >> R;

    vector<int> a(N + 1);
    for (int i = 0; i < N; i++)
        cin >> a[i + 1];

    vector<vector<int>> dp(N + 1, vector<int>(H, -1));
    dp[0][0] = 0;
    int goto_sleep;
    for (int i = 1; i <= N; i++)
    {
        // cout << i << " " << a[i] << " : \t";
        for (int h = 0; h < H; h++)
        {
            if (dp[i - 1][h] != -1)
            {
                // cout << h << " ";
                // sleeps for a[i] hours
                goto_sleep = (h + a[i]) % H;
                dp[i][goto_sleep] = max(dp[i][goto_sleep], (dp[i - 1][h] + (L <= goto_sleep && goto_sleep <= R)));
                // sleeps for a[i]-1 hours
                goto_sleep = (h + a[i] - 1) % H;
                dp[i][goto_sleep] = max(dp[i][goto_sleep], (dp[i - 1][h] + (L <= goto_sleep && goto_sleep <= R)));
            }
        }
        // cout << endl;
    }
    cout << *max_element(dp[N].begin(), dp[N].end());
}