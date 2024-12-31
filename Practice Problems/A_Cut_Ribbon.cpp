#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int cuts[n + 5];
    memset(cuts, -1, sizeof(cuts));
    vector<int> lengths(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> lengths[i];
        if (lengths[i] <= n) // changed here
            cuts[lengths[i]] = 1;
    }

    sort(lengths.begin(), lengths.end());

    for (int i = lengths[0]; i <= n; i++)
    {
        for (int j = 0; j < 3 && lengths[j] <= i; j++)
        {
            if (cuts[i - lengths[j]] != -1)
                cuts[i] = max(cuts[i - lengths[j]] + cuts[lengths[j]], cuts[i]);
        }
    }

    // for (int i = 0; i < (n + 5); i++)
    //     cout << i << " : " << cuts[i] << endl;
    cout << cuts[n] << endl;
}