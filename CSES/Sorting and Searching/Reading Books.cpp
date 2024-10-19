#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long totalTime = accumulate(arr.begin(), arr.end(), 0ll);
    long long maxTime = *max_element(arr.begin(), arr.end());
    if (totalTime - maxTime <= maxTime)
        cout << 2 * maxTime << endl;
    else
        cout << totalTime << endl;
}