#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template <typename Key, typename Compare = std::less<>>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

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
    multiset<int> leftEnds;
    vector<int> contains(n), contained(n);
    ordered_set<pair<int, int>> prevEnds;

    for (int i = n - 1; i >= 0; i--)
    {
        contains[ranges[i][2]] = prevEnds.order_of_key({ranges[i][1], n});
        prevEnds.insert({ranges[i][1], ranges[i][2]});
    }
    prevEnds.clear();
    for (int i = 0; i < n; i++)
    {
        contained[ranges[i][2]] = prevEnds.size() - prevEnds.order_of_key({ranges[i][1], -1});
        prevEnds.insert({ranges[i][1], ranges[i][2]});
    }
    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << endl;
}