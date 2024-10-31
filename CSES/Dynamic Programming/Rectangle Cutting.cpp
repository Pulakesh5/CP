#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> cut(a + 1, vector<int>(b + 1, a * b));
    for (int i = 1; i <= a; i++)
        cut[i][1] = i - 1;
    for (int i = 1; i <= b; i++)
        cut[1][i] = i - 1;
    for (int i = 1; i <= min(a, b); i++)
        cut[i][i] = 0;
    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            for (int k = 1; k < i; k++)
                cut[i][j] = min(1 + cut[k][j] + cut[i - k][j], cut[i][j]);
            for (int k = 1; k < j; k++)
                cut[i][j] = min(1 + cut[i][k] + cut[i][j - k], cut[i][j]);
        }
    }
    cout << cut[a][b] << endl;
}