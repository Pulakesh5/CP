#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<long long, long long> prevCount;
    prevCount[0] = 1;
    long long prefixSum = 0, diff, subarrayCount = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        diff = prefixSum - target;
        if (prevCount.find(diff) != prevCount.end())
            subarrayCount += prevCount[diff];
        prevCount[prefixSum]++;
    }
    cout << subarrayCount << endl;
}