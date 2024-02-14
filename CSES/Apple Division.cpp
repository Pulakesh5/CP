#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    long long minDiff = 1e18;
    int w1 = 0, w2 = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        w1 = 0;
        w2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                w1 += weights[j];
            else
                w2 += weights[j];
        }
        minDiff = min(minDiff, abs(w1 - w2));
    }
    cout << minDiff << endl;
}
