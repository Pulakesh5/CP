#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b;
    while (n--)
    {
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        int m = (2 * a - b) / 3, n = (2 * b - a) / 3;
        // cout << m << " " << n << endl;
        if ((m >= 0 && n >= 0) && (m * 2 + n == a && m + 2 * n == b) || (m * 2 + n == b && m + 2 * n == a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// max=a, min=b

// 2m+n = a
// m+2n = b
// => m = b-2n

// 2(b-2n)+n = a
// =>2b -3n = a
// => n = (2b-a)/3
// => m = b - (4b-2a)/3 = (2a-b)/3