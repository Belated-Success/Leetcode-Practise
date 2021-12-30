/*
dreamoon likes coloring question
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 998244353
#define MAX 20000000000
#define set_zero(a) memset(a,0,sizeof(a))
#define init_dp(a) memset(a,-1,sizeof(a))
#define trace(x) cerr<<#x<<" "<<endl;
#define N 5000005
#define pi 3.14

ll binpow(ll x,ll n){
    if(n==0) return 1;
    long long u = binpow(x,n/2);
    u = (u*u);
    if(n%2 == 1) u=(u*u);
    return u;
}
string decToBinary(int n){
    string s;
    for(int i=31;i>=0;i--){
        int k=n>>i;
        if(k&1) s.push_back('1');
        else s.push_back('0');
    }
    return s;
}
bool is_prime(ll x){
    for(ll i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

ll power(ll x, ll y, ll p){
    ll res=1;
    x=x%p;
    while(y>0){
        if(y&1) res=(res*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}

ll modInverse(ll n, ll p){
    return power(n,p-2,p);
}

void solve(ll tc){
    ll n,m;cin>>n>>m;
    ll a[m];
    ll sum=0;
    bool ok=true;
    for(ll i=0;i<m;i++){
        cin>>a[i];sum+= a[i];
        if(i + a[i] > n) ok = false;
    }
    if(sum < n) ok = false;
    if(!ok) cout<<"-1\n";
    else{
        for(ll i=0;i<m;i++){
            ll st = i+1;
            ll ans = max(st, n-sum+1);
            cout<<ans<<" ";
            sum -= a[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    // cin>>t;
    ll tc =0;
    while (t--)
    {
        tc++; solve(tc);
    }   
}


