#include <bits/stdc++.h>
using namespace std;

#define int long long
int xpow(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, k;
    cin >> q;
    while (q--)
    {
        cin >> k;

        if (k < 10)
            cout << k << endl;
        else
        {
            int c = 1;
            for (int p = 9;; k -= p, c++, p = 9 * xpow(10, c - 1) * c)
            {
                if (k - p <= 0)
                    break;
            }
            k--;
            int x = k / c;
            int y = k % c;
            int ans = xpow(10, c - 1) + x;
            // cerr<<ans<<' '<<x<<' '<<y<<' '<<n<<' '<<c;
            string s = to_string(ans);
            cout << s[y] << endl;
        }
    }
}