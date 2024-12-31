#include <bits/stdc++.h>

using namespace std;

int dp[101][2];
int arr[101];

int main()
{
    int n, num;
    cin >> n;
    int sum = 0, maxSum = 0, oneCount = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if (num)
        {
            sum -= 1;
            oneCount++;
        }
        else
            sum += 1;

        if (sum < 0)
            sum = 0;
        maxSum = max(maxSum, sum);
        // cout << i << " : " << sum << " " << oneCount << endl;
    }
    if (oneCount == n)
        oneCount--;
    cout << maxSum + oneCount << endl;
}