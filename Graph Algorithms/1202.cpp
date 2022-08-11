#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
 
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))
 
using namespace std;
//using namespace __gnu_pbds;
using pii = pair<long long,long long>;
using ld = long double;
using ll = long long;
 
mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());
 
const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);
 
#define Bint __int128
#define int long long
/* ----------------------------------------  */
const int N = 1e5+10;
const int INF = 1e18;

int n,m;
int dis[N], dp[N], dpmax[N], dpmin[N];
vector<pii>G[N];

void dij(){
	fill(dis,dis+n+1,INF);
	fill(dpmin,dpmin+n+1,INF);
	dis[1] = dpmax[1] = dpmin[1] = 0;
	dp[1] = 1;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(mp(0,1));
	while(!pq.empty()){
		auto [d,u] = pq.top();
		pq.pop();
		if(d>dis[u])
			continue;
		for(auto [v,w]:G[u]){
			if(w+d<dis[v]){
				dis[v] = w+d;
				dp[v] = dp[u];
				dpmin[v] = dpmin[u]+1;
				dpmax[v] = dpmax[u]+1;
				pq.push(mp(w+d,v));
			}
			else if(w+d==dis[v]){
				dp[v] = (dp[v]+dp[u])%mod;
				dpmin[v] = min(dpmin[v],dpmin[u]+1);
				dpmax[v] = max(dpmax[v],dpmax[u]+1);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i=0,u,v,w;i<m;i++){
		cin >> u >> v >> w;
		G[u].pb({v,w});
	}
	dij();
	cout << dis[n] << ' ' << dp[n] << ' ' << dpmin[n] << ' ' << dpmax[n] << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

