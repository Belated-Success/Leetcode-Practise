#pragma GCC optimize "Ofast"
#include<bits/stdc++.h>
using namespace std;
// vector properties
#define sz(s) (int)s.size()
#define f first
#define s second
#define pb push_back
#define all(s) s.begin(), s.end()
// components of action
#define vi vector<int>
#define vvi vector<int>
#define ll long long 
#define ull unsigned ll
#define vll vector<ll>
#define vvll vector<vll>

#define ii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<ii>
#define vvii vector<vii>

const ll BIG_INF = 1e18;
const int mod = 998244353;
const int INF = 1e9 + 7;
const int N = 1e6 + 7;
#define ld long double

template<class T, class G> ostream & operator << (ostream&os, const pair<T, G> & para){ os << para.first << ' ' << para.second; return os; }
template<class T> ostream & operator << (ostream&os, const vector<T> & vec){ for(const T & el : vec) os << el << ' '; return os; }
template<class T> ostream & operator << (ostream&os, const set<T> & vec){ for(const T & el : vec) os << el << ' '; return os; }
template<class T> istream & operator >> (istream&is, vector<T> & vec){ for(T & el : vec) is >> el; return is; }
template<class T, class G> istream & operator >> (istream&os, pair<T, G> & para) {os >> para.first >> para.second; return os; }

template<class T> void setmax(T &a, T b) {a = (a >= b ? a:b); }
template<class T> void setmin(T &a, T b) {a = (a <= b ? a:b); }

int T=0;
int tree[1 << 21];
int lazy[1 << 21];

void push(int u, int dl){
    if(lazy[u]){
        tree[u] = dl;
        if(u < T){
            lazy[u+u] = 1;
            lazy[u+u+1] = 1;
        }

        lazy[u] = 0;
    }
}

void set_zeros(int pocz, int kon, int u, int lo, int hi){
    push(u, hi - lo + 1);
    if(kon < lo or hi < pocz)
        return;
    
    if(lo >= pocz and hi <= kon){
        lazy[u] = 1;
        push(u, hi - lo + 1);
        return;
    }
    
    int mid = (hi+lo)/2;
    set_zeros(pocz, kon, u+u, lo, mid);
    set_zeros(pocz, kon, u+u+1, mid+1, hi);
    tree[u] = tree[u+u] + tree[u+u+1];
}

void set_zeros(int pocz, int kon){
    set_zeros(pocz, kon, 1, 0, T-1);
}

int number_of_zeros(int pocz, int kon, int u, int lo, int hi){
    push(u, hi - lo + 1);
    if(kon < lo or hi < pocz)
        return 0;
    if(lo >= pocz and hi <= kon)
        return tree[u];
    
    int mid = (hi+lo)/2;
    return number_of_zeros(pocz, kon, u + u, lo, mid) + number_of_zeros(pocz, kon, u + u + 1, mid + 1, hi);
}

int number_of_zeros(int pocz, int kon){
    return number_of_zeros(pocz, kon, 1, 0, T-1);
}

int pozycja(int poz){
    return poz+1 - number_of_zeros(0, poz);
}
void solve(){
    vector<set<int>> neighboring(26);
    vector<int> nast(26);
    set<int> global;

    string s;
    cin>>s;
    int n = sz(s);

    T = 1;
    while(T<n)
        T *= 2;
    for(int i=0;i<T+T;i++)
        tree[i] = lazy[i] = 0;

    map<int, int>where;
    for(int i=0;i<n;i++)
        if(s[i] == s[i+1]){
            global.insert(i);
            neighboring[s[i] - 'a'].insert(i);
            where[i] = s[i] - 'a';
        }
    
    vii ans;
    while(sz(global)){
        int most = -1;
        int id = -1;
        for(int i=0;i<26;i++)   
            if(sz(neighboring[i]) > most){
                most = sz(neighboring[i]);
                id = i;
            }
        // cout << "Happy new year: "<< global <<endl;
        // cout << "ILE A"<< neighboring[0] <<endl;
        // cout << "ILE B"<< neighboring[1] <<endl;
        // cout << "MOST "<< most << ' ' << id << endl;
        // most famous approach
        while (true)
        {
            auto it = neighboring[id].lower_bound(nast[id]);
            auto inny = global.upper_bound(*it);

            if(inny == global.end()){
                
                it = global.lower_bound(*neighboring[id].begin());
                if(it == global.begin()){

                    int a = *it;
                    ans.pb({pozycja(a), pozycja(a)});
                    neighboring[id].erase(a);
                    global.erase(a);
                    set_zeros(a, a);
                    break;
                }
                else
                {

                }
            }
        }
        
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;cin>>test;
    for(int i=1;i<=test;i++)
        solve();
    return 0;
}