#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool allNegative = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
            allNegative = false;
    }
    if (allNegative)
    {
        cout << *max_element(a.begin(), a.end()) << endl;
        return 0;
    }

    long long sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = max(sum + a[i], 0ll + a[i]);
        if (sum > maxSum)
            maxSum = sum;
        // cout << i << ", " << sum << " " << maxSum << endl;
    }
    cout << maxSum << endl;
}