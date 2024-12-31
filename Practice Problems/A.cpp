#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = false;
    if (n == 2)
    {
        sort(a.begin(), a.end());
        if (2 * a[0] > a[1])
            flag = true;
    }
    else
    {
        for (int i = 0; i < (n - 1); i++)
        {
            int mn = min(a[i], a[i + 1]);
            int mx = max(a[i], a[i + 1]);
            if (2 * mn > mx)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {

        solve();
    }
}