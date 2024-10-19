#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ranges(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
    sort(ranges.begin(), ranges.end(), comp);
    int minRight = 2e9;
    vector<int> contains(n), contained(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (ranges[i][1] >= minRight)
            contains[ranges[i][2]] = 1;
        minRight = min(minRight, ranges[i][1]);
    }

    int maxRight = 0;
    for (int i = 0; i < n; i++)
    {
        if (ranges[i][1] <= maxRight)
            contained[ranges[i][2]] = 1;
        maxRight = max(maxRight, ranges[i][1]);
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << endl;
}