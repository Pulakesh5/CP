#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int digitSum;
    cin >> digitSum;
    if (n == 1 && digitSum == 0)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    if (digitSum == 0 || digitSum > (n * 9))
    {
        cout << -1 << " " << -1;
        return 0;
    }
    vector<int> minNum(n, 0), maxNum(n, 0);

    int remaining = digitSum - 1, extra;
    // making the minNum
    minNum[n - 1] = 1;
    for (int i = 0; i < n && remaining; i++)
    {
        extra = min(remaining, 9);
        minNum[i] += extra;
        remaining -= extra;
    }
    remaining = digitSum;
    // making the maxNum
    for (int i = n - 1; i >= 0 && remaining; i--)
    {
        extra = min(remaining, 9);
        maxNum[i] = extra;
        remaining -= extra;
    }

    for (int i = n - 1; i >= 0; i--)
        cout << minNum[i];
    cout << " ";
    for (int i = n - 1; i >= 0; i--)
        cout << maxNum[i];
    cout << endl;
}