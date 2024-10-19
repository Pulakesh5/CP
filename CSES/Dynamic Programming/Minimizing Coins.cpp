#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins, coins + n);

    vector<int> minimumCoin(x + 5, -1);
    minimumCoin[0] = 0;
    for (int amount = 1; amount <= x; amount++)
    {
        for (int c = 0; c < n; c++)
        {
            if (coins[c] > amount)
                break;
            if (minimumCoin[amount - coins[c]] == -1)
                continue;
            if (minimumCoin[amount] == -1)
                minimumCoin[amount] = minimumCoin[amount - coins[c]] + 1;
            else
                minimumCoin[amount] = min(minimumCoin[amount - coins[c]] + 1, minimumCoin[amount]);
        }
    }

    cout << minimumCoin[x] << endl;
}