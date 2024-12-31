#include <bits/stdc++.h>

using namespace std;

int N, K, Z;
// int rec(int arr[], int moves, int index, int total_left_till_now, int is_last_move_left)
// {
//     if (moves == K || index <= 0 || total_left_till_now > Z)
//         return 0;
//     int left = rec(arr, moves + 1, index - 1, total_left_till_now + 1, is_last_move_left);
//     int right = rec(arr, moves + 1, index + 1, total_left_till_now, is_last_move_left);
//     return max(left, right);
// }

int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> K >> Z;

        int arr[N + 1];
        for (int i = 0; i < N; i++)
            cin >> arr[i + 1];
        long long prefixSum[N + 1];
        prefixSum[0] = 0;
        for (int i = 0; i < N; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + arr[i + 1];
            // cout << prefixSum[i + 1] << " ";
        }
        // cout << endl;
        long long ans = prefixSum[++K];

        for (int moves = 1; moves < K; moves++)
        {
            // cout << moves << endl;
            for (int left = 1; left <= Z; left++)
            {
                int last = K - 2 * left;
                if (last < moves)
                    continue;
                // cout << "\t" << left << " : " << prefixSum[last + 1] << " " << arr[moves] << " " << arr[moves + 1] << endl;
                ans = max(ans, prefixSum[last] + left * (arr[moves] + arr[moves + 1]));
            }
        }
        // cout << "ans = " << ans << endl;
        cout << ans << endl;
    }
    // rec(arr, moves, currIndex, total_left_till_now, is_last_move_left);

    // int prev_move[N + 1][6][2], curr_move[N + 1][6][2];
    // vector<bool> rechable(N + 1, false);
    // memset(prev_move, -1, sizeof(prev_move));
    // memset(curr_move, -1, sizeof(curr_move));

    // for (int moves = 1; moves <= K; moves++)
    // {
    //     for (int i = 1; i <= N; i++)
    //     {
    //         for (int total_left = 0; total_left <= Z; total_left++)
    //         {
    //             for (int last_move_left = 0; last_move_left <= 1; last_move_left++) // last_move_left
    //             {
    //             }
    //         }
    //     }
    // }
    // int dp[n + 1][6][2]; // dp[i][j][0/1] => maximum score you can achieve by stopping at i-index with no more than total j moves to the left
    //                      // if dp[][][1] => last move is towards the left otherwise right
    // memset(dp, 0, sizeof(dp));

    // dp[2][0][0] = arr[1]; // first move is towards the right
    // for (int move = 2; move <= K; move++)
    // {

    //     for(int i=2; i<=n; i++)
    //     {

    //     }
    // }
}