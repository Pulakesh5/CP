#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b;
    cin >> N >> a >> b;

    long long prefix[N + 1];
    prefix[0] = 0;
    long long num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        prefix[i + 1] = prefix[i] + num;
        // cout << prefix[i + 1] << " ";
    }
    // cout << endl;

    long long ans = -1e18;
    multiset<long long> ms;
    for (int i = a; i <= N; i++)
    {
        if (i > b)
            ms.erase(ms.find(prefix[i - b - 1]));
        // cout << i << " : " << prefix[i - a] << " " << prefix[i] << " [ ";
        // for (auto it : ms)
        //     cout << it << " ";
        // cout << "]" << endl;
        ms.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *ms.begin());
    }
    cout << ans << endl;
}