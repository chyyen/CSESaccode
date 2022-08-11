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
int in[N], out[N];
vector<int>circuit[N], ans, tmp, ANS;
vector<int>G[N];

void dfs(int x){
	tmp.pb(x);
	if(!G[x].empty()){
		auto v = G[x].back();
		G[x].pob();
		dfs(v);
	}
}

void solve(){
	cin >> n >> m;
	for(int i=0,u,v;i<m;i++){
		cin >> u >> v;
		out[u]++;
		in[v]++;
		G[u].pb(v);
	}
	if(in[1]+1!=out[1] || out[n]+1!=in[n]){
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int i=2;i<n;i++){
		if(in[i]!=out[i]){
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	dfs(1);
	ans = tmp;
	while(!ans.empty()){
		int u = ans.back();
		ans.pob();
		if(!G[u].empty()){
			tmp.clear();
			dfs(u);
			for(auto i:tmp)
				ans.pb(i);
		}
		else
			ANS.pb(u);
	}
	reverse(all(ANS));
	if(ANS.size()<m+1)
		cout << "IMPOSSIBLE\n";
	else{
		for(auto i:ANS)
			cout << i << ' ';
		cout << '\n';
	}
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

