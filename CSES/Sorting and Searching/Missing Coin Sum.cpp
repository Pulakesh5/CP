#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if (arr[0] > 1)
    {
        cout << 1 << endl;
        return 0;
    }
    set<int> possibleSums;
    long long smallestNotPossible = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (smallestNotPossible < arr[i])
        {
            cout << smallestNotPossible;
            return 0;
        }
        smallestNotPossible += arr[i];
    }
    cout << smallestNotPossible << endl;

    return 0;
}