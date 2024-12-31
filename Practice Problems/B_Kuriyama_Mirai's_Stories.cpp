#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    int arr[n], sorted[n], prefix[n + 1], prefixSorted[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    sort(sorted, sorted + n);
    prefixSorted[0] = 0;

    for (int i = 0; i < n; i++)
        prefixSorted[i + 1] = prefixSorted[i] + sorted[i];

    int q;
    cin >> q;
    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
            cout << prefix[r] - prefix[l - 1] << endl;
        else
            cout << prefixSorted[r] - prefixSorted[l - 1] << endl;
    }
    return 0;
}