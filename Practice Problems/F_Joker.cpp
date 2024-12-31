#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int q;
        cin >> q;
        int pos[q];
        for (int i = 0; i < q; i++)
            cin >> pos[i];
        vector<pair<int, int>> segments;
        segments.push_back({1, -q});
        segments.push_back({m, m});
        segments.push_back({n + q + 1, n});
        for (int i = 0; i < q; i++)
        {
            bool insert = false;
            for (auto &[l, r] : segments)
            {
                if (pos[i] < l)
                    l = max(1ll, l - 1);
                else if (pos[i] > r)
                    r = min(n, r + 1);
                else
                {
                    insert = true;
                    if (l == r)
                        l = n + q, r = -q;
                }
            }
            if (insert)
            {
                segments[0] = {1, max(1ll, segments[0].second)};
                segments[2] = {min(segments[2].first, n), n};
            }
            int left = 0, right = -1, ans = 0;
            for (auto &[l, r] : segments)
            {
                if (l > r)
                    continue;
                if (l > right)
                {
                    ans += max(0ll, right - left + 1);
                    left = l;
                    right = r;
                }
                right = max(right, r);
            }
            ans += max(0ll, right - left + 1);
            cout << ans << ' ';
        }
        cout << endl;
    }
}