#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    string dna;
    cin >> dna;
    int sz = dna.size(), maxLen = 1, len = 1;
    char prev = dna[0];
    for (int i = 1; i < sz; i++)
    {
        if (dna[i] != prev)
        {
            maxLen = max(maxLen, len);
            prev = dna[i];
            len = 1;
        }
        else
            len++;
    }
    maxLen = max(maxLen, len);
    cout << maxLen << endl;
    return 0;
}