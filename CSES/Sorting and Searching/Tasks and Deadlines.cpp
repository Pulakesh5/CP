#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> tasks(n + 5, vector<long long>(2));
    int duration, deadline;
    for (int i = 0; i < n; i++)
    {
        cin >> duration >> deadline;
        tasks[i][0] = duration;
        tasks[i][1] = deadline;
    }
    sort(tasks.begin(), tasks.begin() + n);
    long long currTime = 0;
    long long totalReward = 0;
    for (int i = 0; i < n; i++)
    {
        currTime += tasks[i][0];
        totalReward += (tasks[i][1] - currTime);
    }
    cout << totalReward << endl;
}