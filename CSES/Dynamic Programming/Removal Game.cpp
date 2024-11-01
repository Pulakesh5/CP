#include <bits/stdc++.h>
using namespace std;

long long findMax(int l, int r, int arr[], vector<vector<long long>> &dp)
{
    int n = (r - l + 1);

    if (dp[l][r] != -1)
        return dp[l][r];
    else if (n == 3)
    {
        long long maxScore = max(arr[l] + min(arr[l + 1], arr[r]), min(arr[l], arr[l + 1]) + arr[r]);
        return dp[l][r] = maxScore;
    }
    else
    {
        //      opponent            picked first         ,      picked last
        long long pickFirst = arr[l] + min(findMax(l + 2, r, arr, dp), findMax(l + 1, r - 1, arr, dp));
        long long pickLast = arr[r] + min(findMax(l + 1, r - 1, arr, dp), findMax(l, r - 2, arr, dp));
        return dp[l][r] = max(pickFirst, pickLast);
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
        if (i > 0)
            dp[i - 1][i] = max(arr[i - 1], arr[i]);
    }
    cout << findMax(0, n - 1, arr, dp);
    return 0;
}