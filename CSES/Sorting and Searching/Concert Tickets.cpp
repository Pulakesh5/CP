#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ticket;
    map<int, int> ticket_freq;
    vector<int> bids(m);
    for (int i = 0; i < n; i++)
    {
        cin >> ticket;
        ticket_freq[ticket]++;
    }

    for (int i = 0; i < m; i++)
        cin >> bids[i];

    vector<int> bookings(m, -1);

    for (int i = 0; i < m; i++)
    {
        auto lb = ticket_freq.lower_bound(bids[i]);

        if (lb == ticket_freq.end() || lb->first > bids[i])
        {
            if (lb == ticket_freq.begin())
            {
                bookings[i] = -1;
                continue;
            }
            lb--;
        }
        if (lb->second > 0)
        {
            bookings[i] = lb->first;
            lb->second--;
            if (lb->second == 0)
                ticket_freq.erase(lb);
        }
    }

    for (int i = 0; i < m; i++)
        cout << bookings[i] << endl;
}
