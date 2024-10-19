#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> windowFreq;
    long long l = 0, subarrayCount = 0;
    for (int r = 0; r < n; r++)
    {
        // cout << l << ", " << r << " : ";
        windowFreq[arr[r]]++;
        while (windowFreq.size() > k)
        {
            windowFreq[arr[l]]--;
            if (windowFreq[arr[l]] == 0)
                windowFreq.erase(arr[l]);
            l++;
        }
        subarrayCount += (r - l + 1);
        // cout << l << ", " << r << " : " << subarrayCount << endl;
    }

    cout << subarrayCount << endl;
}