#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    unordered_map<int, int> dp;
    // unordered_map<int, pair<int, int>> mp; // contains the first index and length of longest Subsequence ending with Element

    int maxLen = 1, max_element = arr[1];
    for (int i = 1; i <= n; i++)
    {
        dp[arr[i]] = dp[arr[i] - 1] + 1;

        if (dp[arr[i]] > maxLen)
        {
            maxLen = dp[arr[i]];
            max_element = arr[i];
        }
    }
    cout << maxLen << endl;
    vector<int> ans(maxLen);
    int k = maxLen - 1;
    for (int i = n; i > 0 && maxLen; i--)
    {
        if (arr[i] == max_element)
        {
            ans[k--] = i;
            maxLen--;
            max_element--;
        }
    }
    for (int index : ans)
        cout << index << " ";
    return 0;
}