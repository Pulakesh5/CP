#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> timings;
    int entry, exit;
    for (int i = 0; i < n; i++)
    {
        cin >> entry >> exit;
        timings[entry]++;
        timings[exit]--;
    }
    int maxCustomer = 1, currWindow = 0;
    for (auto it : timings)
    {
        currWindow += it.second;
        if (currWindow > maxCustomer)
        {
            maxCustomer = currWindow;
        }
    }
    cout << maxCustomer << endl;
}