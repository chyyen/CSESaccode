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

struct Max_Flow{
	struct Edge{
		int cap,to,rev;
		Edge(){}
		Edge(int _t,int _c,int _r){
			to = _t;
			cap = _c;
			rev = _r;
		}
	};
	const int INF = 1e18;
	int s,t;
	vector<vector<Edge>>G;
	vector<int>dep,iter;
	void addE(int u,int v,int c){
		G[u].pb(Edge(v,c,G[v].size()));
		G[v].pb(Edge(u,0,G[u].size()-1));
	}
	void bfs(){
		queue<int>q;
		q.push(s);
		dep[s] = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(auto i:G[cur]){
				if(i.cap>0 && dep[i.to]==-1){
					dep[i.to] = dep[cur]+1;
					q.push(i.to);
				}
			}
		}
	}
	int dfs(int x,int fl){
		if(x==t)
			return fl;
		for(int _=iter[x];_<G[x].size();_++){
			auto &i = G[x][_];
			if(i.cap>0 && dep[i.to]==dep[x]+1){
				int res = dfs(i.to, min(fl,i.cap));
				if(res<=0)
					continue;
				i.cap -= res;
				G[i.to][i.rev].cap += res;
				return res;
			}
			iter[x]++;
		}
		return 0;
	}
	int Dinic(){
		int res = 0;
		while(1){
			fill(dep.begin(), dep.end(), -1);
			fill(iter.begin(), iter.end(), 0);
			bfs();
			if(dep[t]==-1)
				break;
			int cur;
			while((cur=dfs(s,INF))>0)
				res += cur;
		}
		return res;
	}
	void init(int _n,int _s,int _t){
		s = _s, t = _t;
		G.resize(_n+5);
		dep.resize(_n+5);
		iter.resize(_n+5);
	}
}g;
 
int n,m;

void solve(){
	cin >> n >> m;
	g.init(n,1,n);
	for(int i=0;i<m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		g.addE(u,v,c);
	}
	cout << g.Dinic() << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

