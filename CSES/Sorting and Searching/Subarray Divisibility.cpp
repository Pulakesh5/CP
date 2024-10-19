#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> remainderCount(n);
    remainderCount[0] = 1;
    long long sum = 0, num, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        sum = (sum % n + n) % n;
        count += remainderCount[sum];
        remainderCount[sum]++;
    }
    cout << count << endl;
}