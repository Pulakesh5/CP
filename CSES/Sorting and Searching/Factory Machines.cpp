#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, toy;
    cin >> n >> toy;
    int time[n];
    for (int i = 0; i < n; i++)
        cin >> time[i];
    long long mnTime = *min_element(time, time + n);
    long long low = 1, high = mnTime * toy, minTime, ans = 1e18;
    while (low <= high)
    {
        minTime = (low + high) / 2;
        long long count = 0;
        for (int i = 0; i < n; i++)
            count += (minTime / time[i]);
        if (count >= toy)
        {
            ans = min(ans, minTime);
            high = minTime - 1;
        }
        else
        {
            low = minTime + 1;
        }
    }
    cout << ans << endl;
}