#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n + 5], pos[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    vector<vector<int>> swapped(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        cin >> swapped[i][0] >> swapped[i][1];

    pos[0] = 0;
    pos[n + 1] = n + 1;
    int rounds = 1;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
            rounds++;
    }
    // cout << "initial round " << rounds << endl;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        a = swapped[i][0];
        b = swapped[i][1];
        int num_a = arr[a], num_b = arr[b];
        set<vector<int>> positions;
        // considering old position of num_a
        if (num_a >= 2)
            positions.insert({num_a - 1, num_a});
        if (num_a <= n - 1)
            positions.insert({num_a, num_a + 1});

        // considering old position of num_b
        if (num_b >= 2)
            positions.insert({num_b - 1, num_b});
        if (num_b <= n - 1)
            positions.insert({num_b, num_b + 1});

        for (auto pr : positions)
            rounds -= (pos[pr[0]] > pos[pr[1]]);
        // cout << rounds << " ";
        swap(arr[a], arr[b]);

        pos[num_b] = a;
        pos[num_a] = b;

        for (auto pr : positions)
            rounds += (pos[pr[0]] > pos[pr[1]]);

        cout << rounds << endl;
    }
    return 0;
}

/*
4 2 1 5 3
4 1 2 5 3

*/