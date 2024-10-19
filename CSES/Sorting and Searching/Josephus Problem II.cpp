#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    int n, k;
    cin >> n >> k;

    indexed_set S;

    for (int i = 0; i < n; i++)
        S.insert(i + 1);
    int i = 0;
    while (S.size())
    {
        i += k;
        i %= S.size();
        auto it = S.find_by_order(i);
        cout << *it << " ";
        S.erase(it);
    }

    return 0;
}