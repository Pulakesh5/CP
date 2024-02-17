#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll sum = 0, num;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        sum += num;
    }
    cout << (n * (n + 1)) / 2 - sum << endl;
    return 0;
}