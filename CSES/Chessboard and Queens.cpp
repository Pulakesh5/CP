#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int possibleWay = 0, maybe = 0;
vector<vector<int>> chessboard(N, vector<int>(N, 0));
vector<string> input(N);
bool check(int x, int y)
{
    bool Ok = true;
    for (int i = 0; i < N && Ok; i++)
    {
        if (chessboard[x][i] == 1 || chessboard[i][y] == 1)
            Ok = false;
    }
    for (int i = 0; x - i >= 0 && y - i >= 0 && Ok; i++)
    {
        if (chessboard[x - i][y - i] == 1)
            Ok = false;
    }
    for (int i = 0; x - i >= 0 && y + i < N && Ok; i++)
    {
        if (chessboard[x - i][y + i] == 1)
            Ok = false;
    }
    return Ok;
}
bool finalCheck(void)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (chessboard[i][j] == 1 && input[i][j] == '*')
                return false;
    return true;
}
void placeQueens(int queens)
{

    if (queens == N)
    {
        possibleWay++;
        return;
    }

    for (int j = 0; j < N; j++)
    {
        if (check(queens, j) && input[queens][j] != '*')
        {
            chessboard[queens][j] = 1;
            placeQueens(queens + 1);
            chessboard[queens][j] = 0;
        }
    }
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        input[i] = str;
        for (int j = 0; j < N; j++)
            if (str[j] == '*')
                chessboard[i][j] = 2;
    }

    int queens = 0;

    placeQueens(queens);

    cout << possibleWay << endl;

    return 0;
}