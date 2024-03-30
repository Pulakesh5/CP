#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    int l = 0, r = n - 1;
    sort(weights.begin(), weights.end());
    int gondola = 0;
    while (l < r)
    {

        if (weights[l] + weights[r] <= x)
            l++;

        gondola++;
        r--;
    }
    if (l == r)
        gondola++;
    cout << gondola << endl;
}