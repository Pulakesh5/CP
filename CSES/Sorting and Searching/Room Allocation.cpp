#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> allocation(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b)
         {
        if(a[0]==b[0])
            return a[1]<=b[1];
        return a[0]<b[0]; });

    // for (int i = 0; i < n; i++)
    //     cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;

    int arrival, departure, index;
    for (int i = 0; i < n; i++)
    {
        arrival = v[i][0];
        departure = v[i][1];
        index = v[i][2];
        // cout << arrival << " " << departure << " " << index << " : ";

        if (!pq.empty() && pq.top().first < arrival)
        {
            allocation[index] = allocation[pq.top().second];
            // cout << pq.top().first << " [" << pq.top().second << "] ";
            pq.pop();
        }
        else
        {
            allocation[index] = pq.size() + 1;
        }
        // cout << "   " << allocation[index] << endl;
        pq.push({departure, index});
    }

    cout << *max_element(allocation.begin(), allocation.end()) << endl;
    for (auto al : allocation)
        cout << al << " ";
    cout << endl;
}