#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicant(n), apartment(m);
    for (int i = 0; i < n; i++)
        cin >> applicant[i];
    for (int i = 0; i < m; i++)
        cin >> apartment[i];
    sort(applicant.begin(), applicant.end());
    sort(apartment.begin(), apartment.end());
    int start = 0, allotted = 0;
    for (int i = 0; i < n && start < m; i++)
    {
        int lb = lower_bound((apartment.begin() + start), apartment.end(), (applicant[i] - k)) - apartment.begin();
        if (lb < m && abs(applicant[i] - apartment[lb]) <= k)
        {
            start = lb + 1;
            allotted++;
        }
    }
    cout << allotted << endl;
    return 0;
}