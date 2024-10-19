#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0, windowSum = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        windowSum += arr[r];
        // cout << r << " : " << windowSum << endl;

        while (l < r && windowSum > sum)
            windowSum -= arr[l++];
        if (windowSum == sum)
            count++;
        r++;
    }
    cout << count << endl;

    return 0;
}