#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ranges(n, vector<int>(2));
    unordered_map<int, int> freq_unique;
    vector<int> uniques;
    // vector<int> valid(400005);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i][0] >> ranges[i][1];
        if (ranges[i][0] == ranges[i][1])
        {
            if (freq_unique.find(ranges[i][0]) == freq_unique.end())
                uniques.push_back(ranges[i][0]);
            freq_unique[ranges[i][0]]++;
            // valid[ranges[i][1]] = 1;
        }
        // mx = max(mx, ranges[i][1]);
    }
    sort(uniques.begin(), uniques.end());

    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        int x = ranges[i][0], y = ranges[i][1];
        if (x == y)
        {
            if (freq_unique[x] > 1)
                ans[i] = 0;
        }
        else
        {
            // int diff1 = valid[y] - valid[x - 1];
            auto itx = freq_unique.find(x);
            auto ity = freq_unique.find(y);
            if (itx == freq_unique.end() || ity == freq_unique.end())
                continue;

            int diff1 = lower_bound(uniques.begin(), uniques.end(), y) - lower_bound(uniques.begin(), uniques.end(), x) + 1;
            // cout << i << " " << diff1 << endl;
            // int diff2 = (y * (y + 1)) / 2 - (x * (x - 1)) / 2;
            // cout << i << " : " << diff1 << " " << diff2 << endl;
            if (diff1 == (y - x + 1))
                ans[i] = 0;
        }
    }

    // for (auto it : freq_unique)
    //     cout << it.first << " " << it.second << endl;

    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}
int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << "test case " << tc << endl;
        solve();
    }
}