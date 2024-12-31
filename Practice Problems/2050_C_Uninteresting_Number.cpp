#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &dp, int ind, int count_2, int count_3)
{
    if (ind >= 36)
        return;
    if (count_2 > 0)
    {
        dp[(ind + 2) % 9] = 1;
        solve(dp, ind + 2, count_2 - 1, count_3);
    }
    if (count_3 > 0)
    {
        dp[(ind + 6) % 9] = 1;
        solve(dp, ind + 6, count_2, count_3 - 1);
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        // cout << "TC :" << tc << endl;
        string str;
        cin >> str;
        // squaring of digits is allowed if result is a single digit only
        // only working with 2 and 3 makes sense
        int count_2 = 0, count_3 = 0, digitSum = 0;
        size_t N = str.size();
        for (int i = 0; i < N; i++)
        {
            digitSum += (str[i] - '0');
            if (str[i] == '2')
                count_2++;
            else if (str[i] == '3')
                count_3++;
        }
        vector<int> dp(10, 0);
        dp[digitSum % 9] = 1;
        if (dp[0])
        {
            cout << "YES" << endl;
            continue;
        }
        solve(dp, digitSum % 9, count_2, count_3);

        if (dp[0])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}