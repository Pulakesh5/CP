#include <bits/stdc++.h>
using namespace std;

multiset<long long> upperHalf, lowerHalf;
long long lowerSum = 0, upperSum = 0;
int n, k;

void _insert(int val)
{
    if ((*lowerHalf.rbegin()) < val)
    {
        upperHalf.insert(val);
        upperSum += val;
        if (upperHalf.size() > (k / 2))
        {
            long long shifting = *upperHalf.begin();
            upperHalf.erase(upperHalf.find(shifting));
            lowerHalf.insert(shifting);
            upperSum -= shifting;
            lowerSum += shifting;
        }
    }
    else
    {
        lowerHalf.insert(val);
        lowerSum += val;
        if (lowerHalf.size() > (k + 1) / 2)
        {
            long long shifting = *lowerHalf.rbegin();
            lowerHalf.erase(lowerHalf.find(shifting));
            upperHalf.insert(shifting);
            lowerSum -= shifting;
            upperSum += shifting;
        }
    }
}

void _erase(long long val)
{
    if (upperHalf.find(val) != upperHalf.end())
    {
        upperHalf.erase(upperHalf.find(val));
        upperSum -= val;
    }
    else
    {
        lowerHalf.erase(lowerHalf.find(val));
        lowerSum -= val;
    }
    if (lowerHalf.empty())
    {
        long long shifting = *upperHalf.begin();
        upperHalf.erase(upperHalf.find(shifting));
        lowerHalf.insert(shifting);
        upperSum -= shifting;
        lowerSum += shifting;
    }
}
long long median()
{
    if (k % 2 == 0)
        return 0ll;
    return *lowerHalf.rbegin();
}
int main()
{
    cin >> n >> k;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (k == 1)
    {
        for (int i = 0; i < (n - k + 1); i++)
            cout << 0 << " ";
        return 0;
    }
    lowerSum += arr[0];
    lowerHalf.insert(arr[0]);
    for (int i = 1; i < k; i++)
        _insert(arr[i]);
    cout << upperSum - lowerSum + median() << " ";
    for (int i = k; i < n; i++)
    {
        _erase(arr[i - k]);
        _insert(arr[i]);
        cout << upperSum - lowerSum + median() << " ";
    }
}