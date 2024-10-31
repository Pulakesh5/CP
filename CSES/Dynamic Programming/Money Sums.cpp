#include <bits/stdc++.h>
using namespace std;
bool sum[100005];
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int prevSum = 0, count = 0;
    sum[0] = true;
    for (int i = 0; i < n; i++)
    {
        // cout << arr[i] << " : ";
        vector<int> aux;
        for (int s = 0; s <= prevSum; s++)
        {
            if (sum[s] && sum[s + arr[i]] == false)
            {
                // cout << s << " ";
                count++;
                aux.push_back(s + arr[i]);
            }
        }
        for (auto it : aux)
            sum[it] = true;
        // cout << endl;
        prevSum += arr[i];
    }
    cout << count << endl;
    for (int i = 1; i <= prevSum; i++)
    {
        if (sum[i])
            cout << i << " ";
    }
    cout << endl;
}