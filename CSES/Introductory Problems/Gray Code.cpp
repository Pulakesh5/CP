#include <bits/stdc++.h>
using namespace std;

void generateGrayCode(string &grayCode, int index, vector<string> &grayCodes)
{
    if (index >= grayCode.size())
    {
        grayCodes.push_back(grayCode);
        return;
    }
    generateGrayCode(grayCode, index + 1, grayCodes);
    grayCode[index] = ('1' - grayCode[index]) + '0';
    generateGrayCode(grayCode, index + 1, grayCodes);
}

int main()
{
    int n;
    cin >> n;

    vector<string> grayCodes;
    string grayCode(n, '0');
    generateGrayCode(grayCode, 0, grayCodes);
    for (string code : grayCodes)
        cout << code << endl;

    return 0;
}