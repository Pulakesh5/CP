#include <bits/stdc++.h>
using namespace std;

bool grid[9][9];
int dR[4] = {0, 0, -1, 1};
int dC[4] = {-1, 1, 0, 0};
//            L  R  U  D
map<char, int> dir;
int maxIndex = -1;
int countPath(string path, int index, int curR, int curC)
{
    maxIndex = max(maxIndex, index);
    // vertically split into two disjoint sets
    if ((grid[curR - 1][curC] && grid[curR + 1][curC]) && (!grid[curR][curC - 1] && !grid[curR][curC + 1]))
        return 0;

    // horizontally split into two disjoint sets
    if ((grid[curR][curC - 1] && grid[curR][curC + 1]) && (!grid[curR - 1][curC] && !grid[curR + 1][curC]))
        return 0;

    if (curR == 7 && curC == 1)
    {
        if (index == 48)
        {
            cout << "found Path\n";
            return 1;
        }
        else
            return 0;
    }
    if (index == 48)
        return 0;

    int pathCount = 0;
    int newR, newC;
    grid[curR][curC] = true;
    if (dir.find(path[index]) != dir.end())
    {
        newR = curR + dR[dir[path[index]]];
        newC = curR + dC[dir[path[index]]];
        // cout << curR << ", " << curC << " : " << path[index] << " => ";
        // cout << newR << " " << newC << endl;
        if (!grid[newR][newC])
            pathCount = countPath(path, index + 1, newR, newC);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            newR = curR + dR[i];
            newC = curC + dC[i];
            if (grid[newR][newC])
                continue;
            pathCount += countPath(path, index + 1, newR, newC);
        }
        // cout << pathCount << endl;
    }
    // cout << index << " " << path[index] << endl;
    // cout << curR << " " << curC << " " << pathCount << endl;
    grid[curR][curC] = false;
    return pathCount;
}

int main()
{
    string path;
    cin >> path;

    dir['R'] = 1;
    dir['L'] = 0;
    dir['D'] = 3;
    dir['U'] = 2;
    memset(grid, false, sizeof(grid));
    for (int i = 0; i < 9; i++)
    {
        grid[i][0] = true;
        grid[i][8] = true;
        grid[0][i] = true;
        grid[8][i] = true;
    }
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    int index = 0, startR = 1, startC = 1, cellVisited = 0;
    int ans = countPath(path, index, startR, startC);
    cout << ans << " " << maxIndex << " " << path[maxIndex] << endl;
    ;
}