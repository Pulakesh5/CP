#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int n;
    cin >> n;
    int curr, prev;
    cin >> curr;
    prev = curr;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> curr;
        ans += max(0, prev - curr);
        prev = max(prev, curr);
    }
    cout << ans << endl;
    return 0;
}