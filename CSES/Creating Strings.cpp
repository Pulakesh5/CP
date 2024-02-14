#include <bits/stdc++.h>
using namespace std;

void permuteStrings(int index, string str, set<string> &permutations)
{
    if (index >= str.size())
    {
        permutations.insert(str);
        return;
    }
    permuteStrings(index + 1, str, permutations);
    for (int i = index + 1; i < str.size(); i++)
    {
        if (str[i] == str[index])
            continue;
        swap(str[i], str[index]);
        permuteStrings(index + 1, str, permutations);
        swap(str[i], str[index]);
    }
}
int main()
{
    string str;
    cin >> str;
    set<string> permutations;
    permuteStrings(0, str, permutations);
    cout << permutations.size() << endl;
    for (string perm : permutations)
        cout << perm << endl;
}