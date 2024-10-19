#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i + 1);
    int skip = 0;
    vector<int> removed;
    while (q.size() > 1)
    {
        int child = q.front();
        q.pop();
        if (skip == 0)
            q.push(child);
        else
            removed.push_back(child);
        skip = 1 - skip;
    }
    for (int i = 0; i < n - 1; i++)
        cout << removed[i] << " ";
    cout << q.front() << endl;
    return 0;
}