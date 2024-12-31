#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    const long long MOD = 1e9 + 7;

    map<char, long long> prev, curr;
    prev['D'] = 1;
    prev['A'] = 0;
    prev['B'] = 0;
    prev['C'] = 0;

    for (size_t i = 1; i <= N; i++)
    {
        curr['A'] = (prev['D'] + prev['B'] + prev['C']) % MOD;
        curr['B'] = (prev['A'] + prev['D'] + prev['C']) % MOD;
        curr['C'] = (prev['A'] + prev['B'] + prev['D']) % MOD;
        curr['D'] = (prev['A'] + prev['B'] + prev['C']) % MOD;
        prev = curr;
    }
    cout << curr['D'] << endl;
}