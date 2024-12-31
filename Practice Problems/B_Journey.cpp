#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        int d = n / (a + b + c), r = n % (a + b + c);
        if (r == 0)
            cout << d * 3;
        else if (r <= a)
            cout << d * 3 + 1;
        else if (r <= (a + b))
            cout << d * 3 + 2;
        else
            cout << d * 3 + 3;
        cout << endl;
    }
}