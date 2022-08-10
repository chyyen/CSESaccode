// scc
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

int n,m;
int w[N];
int dp[N];
int sccid[N], cnt, sum;
vector<int>G[N], revG[N];
stack<int>st;
bitset<N>vis;


void dfs(vector<int>*dG, int x, int k=-1){
	vis[x] = 1;
	sccid[x] = k;
	sum += w[x];
	for(int i:dG[x]){
		if(!vis[i])
			dfs(dG,i,k);
		else if(sccid[x]!=sccid[i]){
			// i -> x
			dp[k] = max(dp[k],dp[sccid[i]]);
		}
	}
	if(dG==G)
		st.push(x);
}

void Kosaraju(){
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(G,i);
	vis.reset();
	while(!st.empty()){
		if(!vis[st.top()]){
			sum = 0;
			dfs(revG, st.top(), ++cnt);
			dp[cnt] += sum;
		}
		st.pop();
	}
}

void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> w[i];
	for(int i=0,u,v;i<m;i++){
		cin >> u >> v;
		G[u].pb(v);
		revG[v].pb(u);
	}
	Kosaraju();
	cout << *max_element(dp, dp+1+cnt) << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

