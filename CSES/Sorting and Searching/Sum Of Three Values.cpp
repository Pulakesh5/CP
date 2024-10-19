#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    if (n < 3)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<pair<int, int>> arr(n);
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = {num, i + 1};
    }
    sort(arr.begin(), arr.end());
    long long num1, num2, num3, target;
    for (int i = 0; i < (n - 2) && arr[i].first < x; i++)
    {
        num1 = arr[i].first;
        target = x - num1;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            num2 = arr[l].first;
            num3 = arr[r].first;
            if ((num2 + num3) > target)
                r--;
            else if (num2 + num3 < target)
                l++;
            else
            {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}