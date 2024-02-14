#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n;
    cin >> n;
    if ((n * (n + 1) / 2) & 1)
        cout << "NO" << endl;
    else
    {
        int halfSum = (n * (n + 1)) / 4;
        vector<int> set1, set2;
        int sum = halfSum, k = n;
        while (sum >= k)
        {
            set1.push_back(k);
            sum -= k;
            k--;
        }
        if (sum)
            set1.push_back(sum);
        int removed = sum;
        while (k)
        {
            if (k != removed)
                set2.push_back(k);
            k--;
        }
        int sz1 = set1.size(), sz2 = set2.size();
        cout << "YES\n";
        cout << sz1 << endl;
        for (int i = sz1 - 1; i >= 0; i--)
            cout << set1[i] << " ";
        cout << endl;
        cout << sz2 << endl;
        for (int i = sz2 - 1; i >= 0; i--)
            cout << set2[i] << " ";
        cout << endl;
    }
}

// n=4 =>