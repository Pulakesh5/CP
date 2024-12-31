#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool pos = (arr[0] > 0);
        long long maxSum = 0, maxElement;
        for (int i = 0; i < n;)
        {
            if (pos)
            {
                maxElement = arr[i];
                i++;
                while (i < n && arr[i] > 0)
                {
                    maxElement = max(maxElement, arr[i]);
                    i++;
                }
                maxSum += maxElement;
                pos = 1 - pos;
            }
            else
            {
                maxElement = arr[i];
                i++;
                while (i < n && arr[i] < 0)
                {
                    maxElement = max(maxElement, arr[i]);
                    i++;
                }
                maxSum += maxElement;
                pos = 1 - pos;
            }
            // cout << i << " " << maxElement << endl;
        }
        cout << maxSum << endl;
        // cout << endl;
    }
}