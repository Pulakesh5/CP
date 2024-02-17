#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int row, col, ans = -1;
        cin >> row >> col;

        if (row <= col)
        {
            if (col & 1)
            {
                ans = col * col;
                for (int i = 1; i < row; i++)
                    ans--;
            }
            else
            {
                ans = (col - 1) * (col - 1) + 1;
                for (int i = 1; i < row; i++)
                    ans++;
            }
        }
        else
        {
            if (row & 1)
            {
                ans = (row - 1) * (row - 1) + 1;
                for (int i = 1; i < col; i++)
                    ans++;
            }
            else
            {
                ans = row * row;
                for (int i = 1; i < col; i++)
                    ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}