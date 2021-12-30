/* --------Codeforces
// Drazil like heap ----Contest#631--------
*/

// #include<bits/stdc++.h>
// using namespace std;
// #define pii pair<int, int>
// const int N = 5000005;
// int a[N], b[N], tmp[N], fl[N];
// void calc(int x)
// {
//     while(1)
//     {
//         int ls = x<<1, rs = x<<1 | 1;
//         if(a[ls] == 0 && a[rs] ==0)
//             return (void)(a[x] = 0);
//         if(a[ls] > a[rs])
//             swap(a[ls], a[x]), x = ls;
//         else
//             swap(a[rs], a[x]), x = rs;
//     }
// }
// vector<int> vec;
// int solve_vec(int x)
// {
//     vec.clear();
//     while(1)
//     {
//         vec.push_back(x);
//         int ls = x<<1,rs = x<<1 | 1;
//         if(a[ls] == 0 && a[rs] == 0)
//             return x;
//         if(a[ls] > a[rs])
//             x = ls;
//         else
//             x = rs;
//     }
// }
// int to(int x)
// {
//     while(1)
//     {
//         int ls = x<<1,rs = x<<1 | 1;
//         if(a[ls] == 0 && a[rs] == 0)
//             return x;
//         if(a[ls] > a[rs])
//             x = ls;
//         else
//             x = rs;
//     }
// }
// int dep[N];
// void solve()
// {
//     vec.clear();
//     int h,g;
//     cin>>h>>g;
//     int n = (1<<h) -1;
//     int l = 1<<g;
//     for(int i=1;i<=n;++i)
//         cin>>a[i],dep[i] = dep[i>>1] + 1;
//     vector<int> ans;
//     long long sum = 0;
//     for(int i=1;i <= n; ++i)
//         while(a[i]!= 0 && dep[to(i)] > g)
//             ans.push_back(i), calc(i);
//     for(int i=1;i< (1<<g); ++i)
//         sum += a[i];
//     cout<<sum<<"\n";
//     for(int v:ans)
//         cout<<v<<" ";
//     cout<<"\n";
//     fill(a+1,a+n+1,0);
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int t = 1;cin>>t;
//     while(t--)
//         solve();
// }

#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cout<<#x<<'='<<(x)<<' ' 

const int N=3e6+10;

int h,g;
int a[N];
bool flag[N];
int it[N];
priority_queue<pair<int,int> > q;

void update(int p){
	if(!a[p<<1]&&!a[p<<1|1]){
		a[p]=0;
		return;
	}
	if(a[p<<1]>a[p<<1|1]){
		a[p]=a[p<<1];
		update(p<<1);
	}
	else{
		a[p]=a[p<<1|1];
		update(p<<1|1);
	}
	if(p>=(1<<g-1)&&p<(1<<g)&&!a[p<<1]&&!a[p<<1|1])flag[p]=1;
	else{
		if(a[p<<1]>a[p<<1|1])it[p]=(p<<1);
		else it[p]=(p<<1|1);
		if(flag[it[p]]){
			flag[p]=1;
			if(!flag[it[p]^1])q.push({a[it[p]^1],it[p]^1});
		}
	}
}

void solve(){
	q=priority_queue<pair<int,int> >();
	scanf("%d%d",&h,&g);
	LL sum=0;
	memset(flag,0,sizeof(bool)*((1<<h+1)+10));
	memset(a,0,sizeof(int)*((1<<h+1)+10));
	for(int i=1;i<(1<<h);i++)scanf("%d",&a[i]),sum+=a[i];
	q.push({a[1],1});
	vector<int> steps;
	for(int i=1;i<=(1<<h)-(1<<g);i++){
		int now=q.top().second;q.pop();
		steps.push_back(now);
		sum-=a[now];
		update(now);
		if(!flag[now])q.push({a[now],now});
	}
	printf("%lld\n",sum);
	for(auto i:steps)printf("%d ",i);
	puts("");
}

int main(){
//	freopen("aaa.txt","r",stdin);
	int ttt=1;
	scanf("%d",&ttt);
	for(int i=1;i<=ttt;i++)solve();
	
	return 0;
}



