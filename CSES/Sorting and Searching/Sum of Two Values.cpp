#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1, sum;
    while (left < right)
    {
        sum = arr[left][0] + arr[right][0];
        if (sum == x)
        {
            cout << arr[left][1] + 1 << " " << arr[right][1] + 1 << endl;
            return 0;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}