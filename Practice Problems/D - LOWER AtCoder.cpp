#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
/*
-----------------------------------------------

 Author : Pulakesh
 Target : CM by Sep'24
 Solution Idea :
-----------------------------------------------
*/
#pragma GCC optimize("O3,unroll-loops")
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vs vector<string>
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define vb vector<bool>
#define nl '\n';
#define ll long long
#define ull unsigned long long
#define lld long long double
#define pb emplace_back
#define ff first
#define ss second
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int set_bits(int n)
{
    return __builtin_popcount(n);
}
#define int long long int
#define nodig(N) (floor(log10(N)) + 1)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define sz(x) ((int)(x).size())
#define PI 3.141592653589793238462
#define PI_STR = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define debug(x)        \
    cerr << #x << ": "; \
    _print(x);          \
    cerr << endl;

void _print(ll t)
{
    cerr << t;
}
// void _print(int t) {cerr << t;}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
void _print(ull t) { cerr << t; }
void print(vector<int> a)
{
    for (auto it : a)
        cerr << it << " ";
}
const ll MOD = 1000000007;
const ll mod = 998244353;
const double eps = 1e-9;
const int MX = 1003;

/*-----------------------------CODE STARTS HERE-------------------------*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    if (a == b)
        return a;
    if (a > b)
        return gcd(b, a % b);
    return gcd(b % a, a);
}
bool isprime(int num)
{
    if ((num % 2) == 0)
        return false;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2)
    {
        if ((num % i) == 0)
            return false;
    }
    return true;
}
int dist(int x, int y, int lx, int ly)
{
    return abs(lx - x) + abs(ly - y);
}
ll _pow(ll n, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}
void solve()
{
    int len;
    cin >> len;
    string s;
    cin >> s;

    int q, x, t;
    char c;
    cin >> q;
    vector<int> lastUpdate(len + 1, -1);
    int second = -1, third = -1;
    for (int i = 0; i < q; i++)
    {
        cin >> t >> x >> c;
        if (t == 1)
        {
            s[x - 1] = c;
            lastUpdate[x - 1] = i;
        }
        else if (t == 2)
            second = i;
        else
            third = i;
    }
    bool upper = (third > second), lower = (second > third), unchanged = (second == third);
    // cout << second << " " << third << nl;
    // cout << upper << " " << lower << nl;
    // cout << nl;
    for (int i = 0; i < len; i++)
    {
        if (lastUpdate[i] == -1)
        {
            if (unchanged)
                continue;
            else if (upper)
                s[i] = (char)toupper(s[i]);
            else
                s[i] = (char)tolower(s[i]);
        }
        else
        {
            // cout << i << " " << lastUpdate[i]
            //  << " " << s[i] << nl;
            if (lastUpdate[i] > max(third, second))
                continue;
            if (upper)
                s[i] = (char)toupper(s[i]);
            else
                s[i] = (char)tolower(s[i]);
            // cout << i << " " << lastUpdate[i]
            //  << " " << s[i] << nl;
        }
    }

    cout << s << nl;

    return;
}

int32_t main()
{
    fastio();
    auto start = chrono::system_clock::now();
    {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

        int test = 1, i = 1;
        // cin >> test;
        while (test--)
        {
            // cout << "Case #" << i << ": ";
            // cerr<<"\nCase #"<<i<<": \n";
            i++;
            solve();
            // cout << '\n';
        }
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - start;
    // cerr<<"Time taken: "<<elapsed.count()<<" sec";
    return 0;
}
