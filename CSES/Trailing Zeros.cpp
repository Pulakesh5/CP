#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long div = 5, count = 0;

    while (div <= n)
    {
        count += (n / div);
        div = div * 5;
    }
    cout << count << endl;

    return 0;
}