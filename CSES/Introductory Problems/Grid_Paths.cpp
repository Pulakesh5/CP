#include <bits/stdc++.h>
using namespace std;

bool grid[9][9];
int dR[4] = {0, 0, -1, 1};
int dC[4] = {-1, 1, 0, 0};
//            L  R  U  D
const int PATHLEN = 48;
int path[PATHLEN];
int maxIndex = -1;
int countPath(int index, int curR, int curC)
{
    maxIndex = max(maxIndex, index);
    // vertically split into two disjoint sets
    if ((grid[curR - 1][curC] && grid[curR + 1][curC]) &&
        (!grid[curR][curC - 1] && !grid[curR][curC + 1]))
        return 0;

    // horizontally split into two disjoint sets
    if ((grid[curR][curC - 1] && grid[curR][curC + 1]) &&
        (!grid[curR - 1][curC] && !grid[curR + 1][curC]))
        return 0;

    if (grid[curR][curC])
        return 0;

    if (curR == 7 && curC == 1)
    {
        if (index == 48)
        {
            // cout << "found Path\n";
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

    if (path[index] == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            newR = curR + dR[i];
            newC = curC + dC[i];
            if (grid[newR][newC])
                continue;
            pathCount += countPath(index + 1, newR, newC);
        }
    }
    else
    {

        newR = curR + dR[path[index]];
        newC = curC + dC[path[index]];
        // cout << path[index] << " " << curR << ", " << curC << " => " << newR << ", " << newC << endl;
        if (!grid[newR][newC])
            pathCount += countPath(index + 1, newR, newC);
    }

    grid[curR][curC] = false;
    return pathCount;
}

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < PATHLEN; i++)
    {
        if (str[i] == 'L')
            path[i] = 0;
        else if (str[i] == 'R')
            path[i] = 1;
        else if (str[i] == 'U')
            path[i] = 2;
        else if (str[i] == 'D')
            path[i] = 3;
        else
            path[i] = 4;
    }

    memset(grid, false, sizeof(grid));
    for (int i = 0; i < 9; i++)
    {
        grid[i][0] = true;
        grid[i][8] = true;
        grid[0][i] = true;
        grid[8][i] = true;
    }

    int index = 0, startR = 1, startC = 1;
    int ans = countPath(index, startR, startC);
    // for (int i = 0; i < PATHLEN; i++)
    //     cout << path[i] << " ";
    // cout << endl;
    cout << ans << endl;
    ;
}