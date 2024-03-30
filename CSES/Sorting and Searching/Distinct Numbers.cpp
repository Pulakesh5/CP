#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int prev = arr[0], distinct = 0, k = 0;
    while (k < n)
    {
        while (k < n && arr[k] == prev)
            k++;
        distinct++;
        if (k < n)
            prev = arr[k];
    }
    cout << distinct << endl;
}