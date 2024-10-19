#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<pair<int, int>> increasingStack;
    increasingStack.push({0, 0});
    for (int i = 0; i < n; i++)
    {
        while (increasingStack.top().first >= arr[i])
            increasingStack.pop();
        cout << increasingStack.top().second << " ";
        increasingStack.push({arr[i], i + 1});
    }
    cout << endl;
}
