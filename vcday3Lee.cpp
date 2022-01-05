// Problem: C. Balanced Stone Heaps
// url : https://codeforces.com/contest/1623/problem/C
// memory linit : 256MB
// time limit : 1000ms

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <functional>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> index_multiset;
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> index_set;
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fixed cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<vi>
#define si vector<string>
#define sii vector<si>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9

#define For(ind,end) for(ind=0;ind<end;++ind)
#define For1(ind,begin,end) for(ind=begin;ind<end;++ind)
#define rFor(ind,end) for(ind=end-1;ind>=0; ind--)
#define Each(ptr,cont) for(auto ptr: cont)

#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
#ifdef DEBUG
    mt19937 gen(857204); //threat lib
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
// void flush() { cout << flush; }
// void println() { cout << '\n'; }
// template<class T> void print(const T &x) { cout << x; }
// template<class T> void read(T &x) { cin >> x; }
// template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
// template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
// template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }
 
// #ifdef DEBUG
//     template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
//     template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
//     string pdbg(const string &s) { return "\"" + s + "\""; }
//     template<class It> string pdbg(It begin, It end, string d);
//     template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
//     template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
//     template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
//     template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
//     template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
//     template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
//     template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
//     template<class It> string pdbg(It begin, It end, string d) {
//         string ans;
//         ans += "{";
//         if (begin != end) ans += pdbg(*begin++);
//         while (begin != end)
//             ans += "," + d + pdbg(*begin++);
//         ans += "}";
//         return ans;
//     }
//     template<class T> string dbgout(const T &x) { return pdbg(x); }
//     template<class T, class... U>
//     string dbgout(T const &t, const U &... u) {
//         string ans = pdbg(t);
//         ans += ", ";
//         ans += dbgout(u...);
//         return ans;
//     }
//     #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
//     #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
// #else
//     #define dbg(...) 0
//     #define msg(...) 0
// #endif

void solve(){

    ll n,i,ans=1e9;cin>>n;
        ll a[n+1];
        for(i=1;i<=n;i++) cin>>a[i];
        ll l=0,r=1e9;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            ll b[n+1];
            vi c(n+1);
            for(i=1;i<=n;i++) b[i]=a[i];
            ll flag=1;
            for(i=n;i>2;i--)
            {
                // b[i] -> mid , c[i]
                // can go up to mid-c[i]
                if(b[i]+c[i]<mid) {flag=0;break;}
                ll x=min(b[i]/3,(b[i]-mid+c[i])/3);
                c[i-1]+=x;
                c[i-2]+=2*x;
                
            }
            if(b[1]+c[1]<mid || b[2]+c[2]<mid) flag=0;
            if(flag) ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<endl;
}

/*-------------------------------------------------------------------------------*/
signed main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    /*----------------------------------------------------------------------------*/
    fast; fixed;
    int t;cin>>t;
    /*----------------------------------------------------------------------------*/
    while(t--)
       solve();
    /*----------------------------------------------------------------------------*/
    #ifndef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    /*----------------------------------------------------------------------------*/    
        
}