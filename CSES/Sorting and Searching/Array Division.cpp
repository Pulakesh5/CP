#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long arr[n], prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cin >> prefixSum[i + 1];
        prefixSum[i + 1] = arr[i];
        prefixSum[i + 1] += prefixSum[i];
    }
    if (k == 1)
    {
        cout << prefixSum[n] << endl;
        return 0;
    }
    long long totalSum = prefixSum[n];
    long long lowerboundSum = *max_element(arr, arr + n), upperboundSum = totalSum;
    long long min_subarraySum = 1e18;
    while (lowerboundSum <= upperboundSum)
    {
        long long mid = (lowerboundSum + upperboundSum) / 2, windowSum = 0, subarrayCount = 0;
        for (int i = 0; i < n; i++)
        {
            windowSum += arr[i];
            if (windowSum > mid)
            {
                subarrayCount++;
                windowSum = arr[i];
            }
        }
        subarrayCount += (windowSum > 0);

        if (subarrayCount > k)
            lowerboundSum = mid + 1;
        else
        {
            min_subarraySum = min(min_subarraySum, mid);
            upperboundSum = mid - 1;
        }
    }
    cout << min_subarraySum << endl;
}