#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    size_t len = str.size();
    if (len < 4)
    {
        cout << "NO";
        return 0;
    }

    // bool ab = 0, ba = 0;
    // if (str[0] == 'A' && str[1] == 'B')
    //     ab = true;
    // else if (str[0] == 'B' && str[1] == 'A')
    //     ba = true;

    vector<vector<bool>> dp(len + 5, vector<bool>(2)); // dp[i][0] = 1 if AB exits, dp[i][1] = if BA exits till index [i]
    if (str[0] == 'A' && str[1] == 'B')
        dp[1][0] = true;
    else if (str[0] == 'B' && str[1] == 'A')
        dp[1][1] = true;

    for (int i = 2; i < len; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        if (str[i] == 'A' && str[i - 1] == 'B') // marking BA
        {
            dp[i][1] = true;
            if (dp[i - 2][0])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        else if (str[i] == 'B' && str[i - 1] == 'A') // marking AB
        {
            dp[i][0] = true;
            if (dp[i - 2][1])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    // for (int i = 0; i < len; i++)
    // {
    //     cout << i << " : " << dp[i][0] << " " << dp[i][1] << endl;
    // }

    // if ((dp[len - 1][0] && dp[len - 3][1]) || (dp[len - 1][1] && dp[len - 3][0]))
    //     cout << "YES" << endl;
    // else
    cout << "NO" << endl;

    return 0;
}