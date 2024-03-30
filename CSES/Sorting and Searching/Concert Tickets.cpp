#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n);
    vector<pair<int, int>> bids(m);
    for (int i = 0; i < n; i++)
        cin >> tickets[i];
    int bid;
    for (int i = 0; i < m; i++)
    {
        cin >> bid;
        bids[i] = {bid, i};
    }

    sort(tickets.begin(), tickets.end());
    sort(bids.begin(), bids.end());
    int bid, start = 0, lb;
    vector<int> bookings(m);
    for (int i = 0; i < m; i++)
    {
        bid = bids[i].first;
        lb = lower_bound(tickets.begin() + start, tickets.end(), bid) - tickets.begin();
        if (lb >= 0 && lb < n &&)
        {
            bookings[i] = tickets[lb];
            start = lb + 1;
        }
        else
            bookings[i] = -1;
    }
}
