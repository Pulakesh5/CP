#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), subseq;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    subseq.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > subseq.back())
            subseq.push_back(arr[i]);
        else
        {
            int index = lower_bound(subseq.begin(), subseq.end(), arr[i]) - subseq.begin();
            // cout << index << " : " << arr[i] << endl;
            subseq[index] = arr[i];
        }
    }
    cout << subseq.size() << endl;
}