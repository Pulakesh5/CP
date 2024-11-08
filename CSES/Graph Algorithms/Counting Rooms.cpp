#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void markRooms(vector<vector<unsigned char>> &building, int i, int j, int m, int n)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    building[i][j] = '$';
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (building[nx][ny] == '.')
                {
                    building[nx][ny] = '$';
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<unsigned char>> building(m, vector<unsigned char>(n));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            cin >> building[i][j];
    }
    int roomCount = 0;

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (building[i][j] == '.')
            {
                roomCount++;
                markRooms(building, i, j, m, n);
            }
        }
    }
    cout << roomCount << endl;
}