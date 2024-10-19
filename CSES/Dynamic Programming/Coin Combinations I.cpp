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
    vector<long long> combination(x + 5);
    const long long MOD = 1e9 + 7;
    combination[0] = 1;
    for (int amount = 1; amount <= x; amount++)
    {
        for (int c = 0; c < n; c++)
        {
            if (coins[c] > amount)
                break;
            combination[amount] = (combination[amount] + combination[amount - coins[c]]) % MOD;
        }
    }
    cout << combination[x] << endl;
}