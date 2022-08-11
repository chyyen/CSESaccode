#include<bits/stdc++.h>
#include<bits/extc++.h>

#define Daredemo_Daisuki ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define FL cout.flush()
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))

using namespace std;
using namespace __gnu_pbds;
using pii = pair<long long,long long>;
using ld = long double;
using ll = long long;

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
// --------------------------------------**
const int N = 1e5+10;

struct edge{
	int to,rev;
	bool vis;
	edge(int t,int r){
		to = t;
		rev = r;
		vis = false;
	}
};

int n,m;
int deg[N];
int idx[N];
vector<int>ans;
vector<edge>G[N];

void find_circuit(int x){
	for(int &_=idx[x];_<G[x].size();_++){
		auto &i = G[x][_];
		if(!i.vis){
			i.vis = true;
			G[i.to][i.rev].vis = true;
			find_circuit(i.to);
		}
	}
	ans.pb(x);
}

void solve(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		G[u].pb(edge(v,G[v].size()));
		G[v].pb(edge(u,G[u].size()-1));
	}
	for(int i=1;i<=n;i++){
		if(deg[i]&1){
			cout << "IMPOSSIBLE\n";
			return;
		}
	}
	find_circuit(1);
	if(ans.size()<m+1){
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(auto i:ans)
		cout << i << ' ';
	cout << '\n';
}

signed main(){
    //Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

