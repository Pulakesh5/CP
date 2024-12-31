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
        int odd = 0, even = 0;
        int n, num;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            if (i & 1)
                odd += num;
            else
                even += num;
        }
        int oddCount = n / 2, evenCount = n - oddCount;
        // cout << even << " " << odd << endl;
        // cout << "Count: " << evenCount << " " << oddCount << endl;

        if ((odd % oddCount == 0) && (even % evenCount == 0) && (odd / oddCount == even / evenCount))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}