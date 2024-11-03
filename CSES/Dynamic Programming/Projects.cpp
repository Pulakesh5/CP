#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Project
    {
        int start = 0;
        int end = 0;
        int reward = 0;
    };
    int n;
    cin >> n;
    vector<Project> Projects(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> Projects[i].start >> Projects[i].end >> Projects[i].reward;
    }
    sort(Projects.begin() + 1, Projects.end(), [](Project &a, Project &b)
         { return a.end < b.end; });

    vector<long long> maxReward(n + 1), lastEnd(n + 1);
    for (int i = 1; i <= n; i++)
        lastEnd[i] = Projects[i].end;

    for (int i = 1; i <= n; i++)
    {
        int last = lower_bound(lastEnd.begin(), lastEnd.end(), Projects[i].start) - lastEnd.begin() - 1;
        maxReward[i] = max(maxReward[i - 1], maxReward[last] + Projects[i].reward);
    }
    cout << maxReward[n];
}
