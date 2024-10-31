#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> books(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> books[i][0];
    for (int i = 0; i < n; i++)
        cin >> books[i][1];

    sort(books.begin(), books.end());
    int remaining;
    vector<int> maxPage(x + 1, 0), aux(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        // cout << amount << " : " << endl;
        for (int amount = 0; amount <= x; amount++)
        {
            remaining = amount - books[i][0];
            maxPage[amount] = aux[amount];
            if (remaining >= 0)
                // cout << maxPage[amount - price] << " " << books[i][1] << endl;
                maxPage[amount] = max(maxPage[amount], aux[remaining] + books[i][1]);
        }
        aux = maxPage;
        // cout << maxPage[amount] << "\n\n";
    }
    cout << maxPage[x] << endl;
}