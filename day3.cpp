/* --------Codeforces
//  Dreamoon like subsequence ----Contest#631--------
*/
#include<bits/stdc++.h>
#include<chrono>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef vector<vector<int>>vvi;
typedef vector<long long>vll;
typedef vector<vll> vvll;
typedef vector<set<int>> graph;
typedef pair<int,int>pii;
typedef vector<pair<int,int>>vpii;
typedef pair<long long, long long> vpll;
typedef pair<long long, long long> pll;

using namespace __gnu_pbds;
template <typename T>
using orderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater_equal<T>>;

//constants
ll MOD = 1e9 + 7;
//end of constants

#define fastio() (ios_base::sync_with_stdio(false),cin.tie(0))
#define sz(x) ((int)x.size())
#define forN(i,n) for(int i=0;i<int(n);i++)
#define forRange(i,l,r) for(int i=0;i< int(n);i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall x.rbegin(), x.rend()
#define rep(n) while(n--)

template <typename T>
istream &operator>>(istream &is, vector<T> &arr)
{
        typename vector<T>::iterator a;
        for(a = arr.begin();a != arr.end(); a++)
        {
            is >> *a;
        }
        return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr)
{
	typename vector<T>::iterator a;
	for (a = arr.begin(); a != arr.end(); a++)
	{
		os << *a << " ";
	}
	return os;
}
//pairs

template <typename T, typename U>
ostream &operator<<(ostream &os,pair <T,U> &p)
{
    os<<p.first<<" "<<p.second<<'\n';
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, vector<pair<T1,T2>>&arr)
{
    typename vector<pair<T1,T2>>::iterator a;
    for(a = arr.begin(); a!= arr.end();a++)
    {
        os<< *a;
    }
    return os;
}
// 

ll mul(ll a, ll b, ll md = MOD)
{
    return (a%md * b%md) %md;
}

ll add(ll a, ll b, ll md=MOD)
{
    ll ans = a+b;
    if(ans>=md)
        ans-=md;
    return ans;
}

bool valid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}

vector<pair<int,int>>dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
#ifdef NUTS
// FILE *in = freopen("input.txt","r",stdin);
FILE *out = freopen("output.txt", "w", stdout);
#endif

ll binPow(ll x, ll y)
{
    ll ans = 1;
    while(y>0)
    {
        if(y%2 == 1)
            ans = mul(ans,x);
        x = mul(x,x);
        y /= 2;
    }
    return ans;
}

ll modInverse(ll x)
{
    return binPow(x, MOD - 2);
}

// discrete combinatorial problem type
vll fac;
ll P(ll n, ll r)
{
    return mul(fac[n], modInverse(fac[n-r]));
}
ll C(ll n, ll r)
{
    return mul(fac[n], mul(modInverse(fac[n-r]), modInverse(fac[r])));
}

// intro to graph like problems
vvi G;
vector<bool> vis;
void DE(int u,int v)
{
    G[u].pb(v);
}

void E(int u,int v)
{
    DE(u,v);
    DE(v,u);
}
void solve()
{
    ll d,m;
    cin>>d>>m;
    // m not a prime number
    MOD = m;
    vi choices;
    ll x=1;
    while(d>0)
    {
        ll c = min(d,x);
        choices.pb(c%m);
        x <<= 1ll;
        d -= c;
    }
    ll ans = 1;
    for(ll x: choices)
    {
        ans = mul(ans, x + 1); // number of non-empty options, +1 for not picking it!
    }
    ans = add(ans,m - 1); // -1 for empty subset
    cout<<ans<<'\n';
}

int main()
{
    fastio();
    int t;
    cin>>t;
    rep(t)
        solve();
}
