#include <bits/stdc++.h>

using namespace std;
#define int long long

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] >= b[0];
}
int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << "TC: " << tc << endl;
        // cout << "index\ta[i]\tb[i]\tnegrev\tprofit\n";
        int n, k;
        cin >> n >> k;

        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int maxProfit = 0;
        for (int i = 0; i < n; i++) // traverse all the prices in a[]
        {
            int bought = n - (lower_bound(b, b + n, a[i]) - b);             // No of people who actually bought the tree
            int no_negative_review = n - (lower_bound(a, a + n, a[i]) - a); // No of people who didn't give a negative review
            if ((bought - no_negative_review) <= k)
                maxProfit = max(maxProfit, bought * a[i]);
        }
        for (int i = 0; i < n; i++) // traverse all the prices in b[]
        {
            int bought = n - (lower_bound(b, b + n, b[i]) - b);             // No of people who actually bought the tree
            int no_negative_review = n - (lower_bound(a, a + n, b[i]) - a); // No of people who didn't give a negative review
            if ((bought - no_negative_review) <= k)
                maxProfit = max(maxProfit, bought * b[i]);
        }
        cout << maxProfit << endl;
    }
}