#include <bits/stdc++.h>

using namespace std;

unsigned char labyrinth[1000][1000];
short int previousStep[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

string direction = "UDLR";

void findPath(int i, int j, int n, int m)
{
    queue<vector<int>> q; // vector[0:2] => position;
                          // vector[2:] => path taken
    vector<int> start = {i, j}, end = start;
    q.push({i, j});
    labyrinth[i][j] = '@';
    vector<int> v;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int p = 0; p < qsize; p++)
        {
            v = q.front();
            q.pop();
            int x = v[0];
            int y = v[1];
            // cout << x << " " << y << " : " << labyrinth[x][y] << endl;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && (labyrinth[nx][ny] == '.' || labyrinth[nx][ny] == 'B'))
                {
                    previousStep[nx][ny] = k;
                    if (labyrinth[nx][ny] == '.')
                    {
                        // cout << "\tPushing: " << nx << " " << ny << endl;
                        labyrinth[nx][ny] = 'P';
                        q.push({nx, ny});
                    }
                    else if (labyrinth[nx][ny] == 'B')
                    {
                        // cout << "\tPushing: " << nx << " " << ny << endl;
                        labyrinth[nx][ny] = '$';
                        end = {{nx, ny}};
                        break;
                    }
                }
            }
        }
    }

    if (labyrinth[end[0]][end[1]] == '$')
    {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start)
        {
            int step = previousStep[end[0]][end[1]];
            steps.push_back(step);
            end = {end[0] - dx[step], end[1] - dy[step]};
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (int dir : steps)
            cout << direction[dir];
        cout << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> labyrinth[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (labyrinth[i][j] == 'A')
            {
                findPath(i, j, n, m);
                return 0;
            }
        }
    }
    return 0;
}