#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long cost = 0, median = arr[n / 2];
    for (int i = 0; i < n; i++)
        cost += abs(median - arr[i]);
    cout << cost << endl;
}