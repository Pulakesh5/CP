#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << "TC " << tc << endl;
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        // map<int, int> freq;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            // freq[a[i]]++;
            total += a[i];
        }
        sort(a.begin(), a.end());
        int pairCount = 0;
        for (int i = 0; i < n; i++)
        {
            int my = total - a[i] - y;
            int mx = total - a[i] - x;
            if (my < 0 && mx < 0)
                continue;
            pairCount += (upper_bound(a.begin() + i + 1, a.end(), mx) - lower_bound(a.begin() + i + 1, a.end(), my));
        }
        cout << pairCount << endl;
    }
}