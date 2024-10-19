#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cube;
    vector<int> tower;
    for (int i = 0; i < n; i++)
    {
        cin >> cube;
        if (tower.size() == 0)
        {
            tower.push_back(cube);
            continue;
        }
        int base = upper_bound(tower.begin(), tower.end(), cube) - tower.begin();
        if (base == tower.size())
            tower.push_back(cube);
        else
            tower[base] = cube;
    }
    cout << tower.size() << endl;
    return 0;
}