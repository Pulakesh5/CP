#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> papers(m), questions(k);
        for (int i = 0; i < m; i++)
            cin >> papers[i];
        long long sum = 0, missing;
        for (int i = 0; i < k; i++)
        {
            cin >> questions[i];
            sum += questions[i];
        }
        missing = ((n * (n + 1)) / 2) - sum;

        string ans(m, '0');
        if (k < (n - 1))
        {
            // cout << "first case" << endl;
            cout << ans << endl;
        }
        else if (k == n)
        {
            string all(n, '1');
            // cout << "second case" << endl;
            cout << all << endl;
        }
        else
        {
            // cout << "third case" << endl;
            int index = lower_bound(papers.begin(), papers.end(), missing) - papers.begin();
            // cout << missing << " " << index << " " << papers[index] << endl;
            if (index >= m || papers[index] != missing)
                cout << ans << endl;
            else
            {
                ans[index] = '1';
                cout << ans << endl;
            }
        }
    }
}