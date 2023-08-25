#include<bits/stdc++.h>
using namespace std;
/*
-----------------------------------------------
  
  Author : Pulakesh
 
-----------------------------------------------
*/

#define vll vector<ll>
#define vvll  vector<vll>
#define vi  vector<int>
#define vs  vector<string>
#define vb  vector<bool>
#define nl '\n';
#define ll long long
#define pb emplace_back
#define F first
#define S second
#define int long long int
#define nodig(N)  (floor(log10(N)) + 1)
#define forn(i,n) for(int i=0;i<(int)n; i++)
#define input(a,n) for(int i=0;i<n;i++) {cin>>a[i];}
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll MOD=  998244353;
const ll mod = 1e9+7;
const double eps = 1e-9;
const int MX = 1e9+1;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
void print(vector<vector<int>> a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cout<<a[i][j]; }
ll sum(ll n) {return (n*(n+1))/2.0;}
ll len( string str) { return str.length();}
ll fact(ll n){ if(n>0) return ((n%MOD)*fact(n-1))%MOD; else return 1;}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

long long dp[1001][1001];
void solve(){
    ll n;
    cin>>n;
    memset(dp,0ll, sizeof(dp));
    
    dp[1][1] = 1;
    
    for(ll i=2; i<=n; i++)
    {
        for(ll j=1; j<=i; j++)
        {
            dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1])%mod;
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans = (ans + dp[n][i])%mod;
    
    cout<<ans;
}
int32_t main(){
    fast_io();

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt", "w", stderr);
    // freopen("output.txt", "w",stdout);
    // #endif //ONLINE_JUDGE
    
    int test=1,i=1;
    cin>>test;
    while(test--){
        //cerr<<"Case #"<<i++<<": \n";
        solve();
        cout<<'\n';
    }
    return 0;
}
