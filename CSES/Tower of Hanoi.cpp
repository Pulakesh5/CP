#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int disks, vector<vector<int>> &moves, int from, int with, int to)
{
    if (disks == 0)
        return;
    towerOfHanoi(disks - 1, moves, from, to, with);
    moves.push_back({from, to});
    towerOfHanoi(disks - 1, moves, with, from, to);
}

int main()
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    vector<vector<int>> moves;
    int from = 1, to = 3, with = 2, disks = n;
    towerOfHanoi(disks, moves, from, with, to);
    for (vector<int> move : moves)
        cout << move[0] << " " << move[1] << endl;

    return 0;
}

// T(n) = T(n-1) [move top n-1 smaller size disks to 'with' stack with 'to' stack]
//        +1     [move last disk to 'to' stack]
//        +T(n-1)[move n-1 disks to 'to' stack to 'to' stack using 'with' stack]

// [3, 0, 0]

// [2, 0, 1] => (1,3)
// [1, 1, 1] => (1,2)
// [1, 2, 0] => (3,2)

// [0, 2, 1] => (1,3)

// [1, 1, 1] => (2,1)
// [1, 0, 2] => (2,3)
// [3, 0, 0] => (1,3)
