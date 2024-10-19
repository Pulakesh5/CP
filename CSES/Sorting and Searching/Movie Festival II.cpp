#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    multiset<int> endTimes;
    for (int i = 0; i < k; i++)
        endTimes.insert(0);
    int maximumNumberOfMovies = 0, currCount = 0;

    for (int i = 0; i < n; i++)
    {
        auto it = endTimes.upper_bound(arr[i].second);
        if (it == begin(endTimes))
            continue;
        endTimes.erase(prev(it));
        endTimes.insert(arr[i].first);
        maximumNumberOfMovies++;
        // cout << arr[i].first << ", " << arr[i].second << " : " << maximumNumberOfMovies << endl;
    }
    cout << maximumNumberOfMovies << endl;
}