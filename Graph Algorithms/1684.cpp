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
int sccid[2*N], cnt;
stack<int>st;
vector<int>G[2*N], revG[2*N];
bitset<2*N>vis;

void dfs(vector<int>*dG,int u,int k=-1){
	vis[u] = 1;
	sccid[u] = k;
	for(int v:dG[u]){
		if(!vis[v])
			dfs(dG,v,k);
	}
	if(dG==G)
		st.push(u);
}

bool Kosaraju(){
	for(int i=0;i<2*n;i++)
		if(!vis[i])
			dfs(G,i);
	vis.reset();
	while(!st.empty()){
		if(!vis[st.top()])
			dfs(revG, st.top(), ++cnt);
		st.pop();
	}
	for(int i=0;i<n;i++)
		if(sccid[i]==sccid[i+n])
			return false;
	return true;
}

void solve(){
	cin >> m >> n;
	for(int i=0,notu,notv,u,v;i<m;i++){
		char a,b;
		cin >> a >> u >> b >> v;
		u--, v--;
		notu = u+n, notv = v+n;
		if(a=='-')
			u += n, notu -= n;
		if(b=='-')
			v += n, notv -= n;
		G[notu].pb(v);
		G[notv].pb(u);
		revG[v].pb(notu);
		revG[u].pb(notv);
	}
	if(Kosaraju()){
		for(int i=0;i<n;i++)
			cout << (sccid[i]<sccid[i+n] ? '-' : '+');
		cout << '\n';
	}
	else
		cout << "IMPOSSIBLE\n";
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

