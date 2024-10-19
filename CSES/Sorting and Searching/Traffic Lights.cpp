#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, n;
    cin >> len >> n;
    vector<int> ans(n);
    set<int> lights;
    lights.insert(0);
    lights.insert(len);
    int pos;
    multiset<int> length;
    length.insert(len);
    for (int i = 0; i < n; i++)
    {
        cin >> pos;
        auto index = lights.upper_bound(pos);
        auto prev = index;
        prev--;
        length.erase(length.find(*index - *prev));
        length.insert(pos - *prev);
        length.insert(*index - pos);
        lights.insert(pos);
        ans[i] = *length.rbegin();
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}