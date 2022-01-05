/*
	code: tech nuts
	github: github: https://github.com/TechNuts01	
	
*/

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
 
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
 
using namespace std;
 
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
 
void flush() { cout << flush; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }
 
#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif
 
template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

//-----------------------------------//
//       Number Theory Template      //
//-----------------------------------//
 
// int mod = 998244353; //CHANGE ACCORDINGLY
// double invmod = 1.0/mod;
 
// template<class T> T cdiv(T a, T b){return (a+b-1)/b;}
// template<class T> T fdiv(T a, T b){return a/b;}
// template<class T> T pow(T a, int n){T x=(n%2)?a:1;
//    if(n<=1)return x; else{T y=pow(a,n/2);return y*y*x;}}
// pair<int,int> bezout(int a, int b){
//    if(a<b){auto p = bezout(b,a);return make_pair(p.second,p.first);}
//    if(b==0) return make_pair(1,0);
//    auto p = bezout(b,a%b);return make_pair(p.second,p.first-p.second*(a/b));
// } //output (x,y) such that ax+by=gcd(a,b)
 
// int m_red(int a){int x=a-((int)(invmod*a) * mod); if(x<0) x+=mod; if(x>=mod) x-=mod; return x}
// struct mint{int v;
//    mint(int _v){v = m_red(_v);}
//    mint(int _v,bool lazy){if(!lazy){
//       if(_v<0) _v+= mod;
//       if(_v>=mod) _v-=mod;
//    }v=_v;} //for only quick reduction
//    // mint inv() const{return mint(bezout(v,mod).first);}
//    friend std::ostream&operator <<(std::ostream&out,const mint&n){int x=n.v;
//       while(x>=mod) x-=mod; while(x<0) x+= mod; return out<<x;}
//    friend std::istream&operator >>(std::istream&in,mint&n){int _v;in>>_v;n=mint(_v);return in;}
//    mint operator -() const {return mint(-v,true);}
//    friend mint operator +(const mint&a,const mint&b){return mint(a.v+b.v,false);}
//    friend mint operator +(const mint&a,const int&b){return mint(a.v+m_red(b),false);}
//    friend mint operator -(const mint&a,const mint&b){return mint(a.v-b.v,false);}
//    friend mint operator -(const mint&a,const int&b){return mint(a.v-m_red(b),false);}
//    friend mint operator -(const int&a,const mint&b){return mint(m_red(a)-b.v,false);}
//    friend mint operator *(const mint&a,const mint&b){return mint(a.v*b.v);}
//    friend mint operator *(const mint&a,const int&b){return mint(a.v*m_red(b));}
//    friend mint operator /(const mint&a,const mint&b){return a*b.inv();}
//    friend mint operator /(const mint&a,const int&b){return a*mint(b).inv();}
//    friend mint operator /(const int&a,const mint&b){return mint(a)*b.inv();}
// };
// mint m_pow(mint a, int n){if(n==0) return mint(1);if(n==1) return a;
//    if(n%2==0){mint x=m_pow(a,n/2);return x*x;}mint x=m_pow(a,n/2); return x*x*a;}
 
// vector<mint> fact; vector<int> prime;
// void init_fact(int bound){fact.push_back(mint(1));for(int i=1;i<bound;i++)fact.push_back(i*fact[i-1]);}
// void init_prime(int bound){prime.push_back(0);prime.push_back(0);
//    for(int i=2;i<=bound;i++)prime.push_back(1);
//    for(int i=2;i*i<=bound;i++){if(prime[i]==1){int j=2*i;while(j<=bound){prime[j]=0;j+=i;}}}}
// mint C(int n,int r){return fact[n]/(fact[n-r]*fact[r]);}
 
void solve(){
    int n,m,nr,nl,nu,nd;read(n); read(m); read(nr); read(nl); read(nu); read(nd);
    int ans=0;
    int dr=1,dc=1;

    while(true){
    	if(nr==nu || nl==nd){
    		cout<<ans<<"\n";
    		break;
    	}
    	if(nr == n){
    		if(dr==1)
    			dr= -1;
    		else
    			dr = 1;
    		
    	}
    	if(nl == m){
    		if(dc==1)
    			dc = -1;  		
    		else
    			dc = 1;
    		
    	}
    	nr += dr;nl += dc;ans++;
    }	
}

/*-------------------------------------------------------------------------------*/
signed main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	/*----------------------------------------------------------------------------*/
	fast; fixed;
	int t;read(t);
    /*----------------------------------------------------------------------------*/
    while(t--)
		solve();
    /*----------------------------------------------------------------------------*/
    #ifndef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    /*----------------------------------------------------------------------------*/    
    return 0;
}
