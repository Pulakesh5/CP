#include <bits/stdc++.h>
using namespace std;

set<int> getDigits(int num)
{
    set<int> digits;
    while (num)
    {
        if (num % 10 != 0)
            digits.insert(num % 10);
        num /= 10;
    }
    return digits;
}
long long rec(int num, vector<long long> &dp)
{
    if (dp[num] != -1)
        return dp[num];
    set<int> digits = getDigits(num);
    long long minStep = 1e9;
    // cout << num << " : " << endl;
    for (auto digit : digits)
    {
        long long step = rec(num - digit, dp);
        // cout << digit << " " << step << endl;Æ
        minStep = min(minStep, 1 + step);
    }
    return dp[num] = minStep;
}
int main()
{
    int n;
    cin >> n;
    if (n < 10)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<long long> dp(n + 5, -1);
    for (int i = 1; i < 10; i++)
        dp[i] = 1;
    cout << rec(n, dp) << endl;
}