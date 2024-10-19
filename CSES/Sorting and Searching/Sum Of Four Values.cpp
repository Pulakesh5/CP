#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    if (n < 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int sum, fourSum, l, r;
    for (int ptr1 = 0; ptr1 < (n - 3); ptr1++)
    {
        for (int ptr2 = ptr1 + 1; ptr2 < (n - 2); ptr2++)
        {
            l = ptr2 + 1;
            r = n - 1;
            sum = arr[ptr1].first + arr[ptr2].first;
            while (l < r)
            {
                fourSum = sum + arr[l].first + arr[r].first;
                if (fourSum < target)
                    l++;
                else if (fourSum > target)
                    r--;
                else
                {
                    cout << arr[ptr1].second + 1 << " " << arr[ptr2].second + 1 << " " << arr[l].second + 1 << " " << arr[r].second + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}