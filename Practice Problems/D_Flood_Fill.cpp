#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &dp, vector<int> &segments, int l, int r)
{
    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];
    int ans;
    if (segments[l] == segments[r])
        ans = 1 + solve(dp, segments, l + 1, r - 1);
    else
        ans = 1 + min(solve(dp, segments, l + 1, r), solve(dp, segments, l, r - 1));
    // cout << l << " " << r << " : " << ans << endl;
    return dp[l][r] = ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> segments;
    int prev = -1, elem;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        if (elem != prev)
        {
            if (prev != -1)
                segments.push_back(prev);
            prev = elem;
        }
    }
    segments.push_back(prev);
    int L = segments.size();

    // cout << "L = " << L << " ";
    // for (int seg : segments)
    //     cout << seg << " ";
    // cout << endl;

    vector<vector<int>> dp(L, vector<int>(L, -1));
    cout << solve(dp, segments, 0, L - 1);
}