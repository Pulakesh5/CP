#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> lastPos;
    int l = -1, r = 0;
    int longestSeq = 1;
    while (r < n)
    {
        if (lastPos.find(a[r]) != lastPos.end() && lastPos[a[r]] > l)
            l = lastPos[a[r]];
        lastPos[a[r]] = r;
        longestSeq = max(longestSeq, r - l);
        r++;
    }
    // longestSeq = max(longestSeq, r - l);
    cout << longestSeq << endl;
}