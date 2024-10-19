#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<vector<int>> &show, int index)
{
    int low = index + 1, high = show.size(), mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (show[mid][0] < show[index][1])
            low = mid + 1;
        else
            high = mid;
    }
    return high; // index of the first show that starts after the current show
}

int watchMovie(vector<vector<int>> &show, int index, vector<int> &dp)
{
    if (index >= show.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int next = binSearch(show, index);
    return dp[index] = max(1 + watchMovie(show, next, dp), watchMovie(show, index + 1, dp));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> showTimings(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> showTimings[i][0] >> showTimings[i][1];
    }
    sort(showTimings.begin(), showTimings.end());
    vector<int> dp(n, -1);
    cout << watchMovie(showTimings, 0, dp);
}