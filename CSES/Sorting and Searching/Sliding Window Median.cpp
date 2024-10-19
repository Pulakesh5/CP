#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    multiset<int> window(arr, arr + k);
    auto midPtr = next(window.begin(), k / 2);
    for (int i = k; i < n; i++)
    {
        cout << min(*midPtr, *prev(midPtr, 1 - k % 2)) << " ";
        window.insert(arr[i]);
        if (arr[i] < *midPtr)
            midPtr--;
        if (arr[i - k] <= *midPtr)
            midPtr++;
        window.erase(window.lower_bound(arr[i - k]));
    }
    cout << min(*midPtr, *prev(midPtr, 1 - k % 2)) << endl;
}