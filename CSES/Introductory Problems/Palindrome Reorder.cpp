#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> charCount(26, 0);
    for (char ch : str)
        charCount[ch - 'A']++;
    int oddCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (charCount[i] & 1)
            oddCount++;
    }
    if (oddCount > 1)
        cout << "NO SOLUTION\n";
    else
    {
        int oddChar = -1;
        string palindromString = "";
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] & 1)
                oddChar = i;
            else if (charCount[i] > 0)
            {
                string pal((charCount[i] / 2), (char)('A' + i));
                palindromString += pal;
            }
        }
        string revPal = palindromString;
        reverse(revPal.begin(), revPal.end());
        if (oddChar != -1)
        {
            string pal((charCount[oddChar]), (char)('A' + oddChar));
            palindromString += pal;
        }
        palindromString += revPal;

        cout << palindromString << endl;
    }
}