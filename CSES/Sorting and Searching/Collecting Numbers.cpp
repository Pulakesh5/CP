#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], pos[n + 1];
    pos[0] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int rounds = 1;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
            rounds++;
    }
    cout << rounds << endl;
}