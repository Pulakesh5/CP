#include <bits/stdc++.h>

using namespace std;
#define int long long

pair<int, int> f(int n, int k) // return count of elements and total values for [1,n]
{
    if (n < k)
        return {0, 0};
    int mid = (n + 1) / 2;
    pair<int, int> sub = f(n / 2, k);
    // cout << n << " :\n\t" << sub.first << " " << sub.second << endl;
    sub.second = 2 * sub.second + mid * sub.first; // value for the whole segment [1,n]
    sub.first = 2 * sub.first;                     // count of elements, considering equal number of elements on both sides
    if (n & 1)
    {
        sub.first++;
        sub.second += mid;
    }
    // cout << "  \t" << sub.first << " " << sub.second << endl;
    return sub;
}
void solve()
{
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
        cout << (n * (n + 1)) / 2 << endl;
        return;
    }
    else
        cout << f(n, k).second << endl;
}
int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << "TC: " << tc << endl;
        solve();
    }
}