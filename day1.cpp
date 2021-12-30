/* Dreamoon Loves AA */
// 

/*
pragma gcc optimize("Ofast")
#pragma gcc optimization("unroll-loops, no-stack-protector") 
#pragma gcc target("avx,avx2,fma")
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=4e5+21;
const ll mod=1e9+7;
const ll base=1e18;
ll p[maxn];
ll a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>> n >> m >> k;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        p[m+1]=n;
        k=k+m+1;
        m++;
        for(int i=1;i<=m;i++)
        {
            a[i]=p[i]-p[i-1];
        }
        ll u;
        ll l=1, h=1e15;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            ll cnt=0;
            // cout<< mid<< endl;
            for(int i=1;i<=m;i++){
                ll t=(a[i]/mid);
                for(ll st=max(1ll,t-2);st<=t+2;st++)
                {
                    if(((a[i]+st-1)/st)<=mid)
                    {
                        cnt+=st;
                        break;
                    }
                }
            }
            if(cnt <= k) h=mid-1;
            else l=mid+1;
        }

        u=l;
        ll v;
        l=1,h=1e15;
        //cout <<(k) <<endl;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            ll cnt=0;
            for(int i=1;i<=m;i++)
            {
                ll t=(a[i]/mid);
                if(a[i]<mid)
                {
                    cnt=0;
                    break;
                }
                for(ll st=t+2;st>=max(1ll,t-2);st--)
                {
                    if((a[i]/st)>=mid)
                    {
                        cnt+=st;
                        break;
                    }
                }
            }
            // cout<< cnt <<" "<<mid<<" chk"<<endl;
            if(cnt>=k)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        v=h;
        //cout<<v<<" "<<u<<endl;
        vector<pll> vt;
        multiset<ll> st;
        ll ans=base;
        for(int i=1;i<=m;i++)
        {
            ll x=(a[i]/v);
            if(((a[i]+x-1)/x)<=u)
            {
                // cout<< a[i] <<" "<<x<<" chk"<<endl;
            }
            else
            {
                ll l=(a[i]/(x+1));
                ll nw=(a[i]/u);
                ll r=base;
                for(ll p=max(1ll,nw-2);p<=nw+2;p++)
                {
                    if(((a[i]+p-1)/p)>u)
                    {
                        r=min(r,((a[i]+p-1)/p));
                    }
                }
                vt.pb(make_pair(r,l));
                st.insert(l);
                // cout<<r<<" "<<l<<endl;
            }
        }
        if(!st.size()) ans=(u-v);
        else
        {
            st.insert(v);
            ans=u-(*st.begin());
            sort(vt.begin(),vt.end());
            for(auto p:vt)
            {
                ll r=p.ff;
                ll l=p.ss;
                auto it=st.lower_bound(l);
                st.erase(it);
                ans=min(ans,r-(*st.begin()));
            }
        }
        cout<< ans<< endl;
    }
}
