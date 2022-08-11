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
const int N = 21; 

int n,m;
int dp[N][1<<N];
vector<int>G[N];

void solve(){
	cin >> n >> m;
	for(int i=0,u,v;i<m;i++){
		cin >> u >> v;
		u--;
		v--;
		G[v].pb(u);
	}
	dp[0][1] = 1;
	for(int i=3;i<(1<<n);i+=2){
		if((i&(1<<(n-1))) && i!=(1<<n)-1)
			continue;
		int x = i;
		while(x){
			int cur = __lg(x&-x);
			for(auto j:G[cur])
				if(j!=cur && i&(1<<j))
					dp[cur][i] = (dp[cur][i]+dp[j][i^(1<<cur)])%mod;
			x -= (x&-x);
		}
	}
	cout << dp[n-1][(1<<n)-1] << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

