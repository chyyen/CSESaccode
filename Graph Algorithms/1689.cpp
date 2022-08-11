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

int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

int ans[10][10];
bitset<10>vis[10];

bool cango(int x,int y){
	return x>0 && x<=8 && y>0 && y<=8 && !vis[x][y];
}

int togo(int x,int y){
	int res = 0;
	for(int i=0;i<8;i++)
		res += cango(x+dx[i],y+dy[i]);
	return res;
}

bool dfs(int x,int y,int dep){
	ans[x][y] = dep;
	vis[x][y] = 1;
	if(dep==64)
		return true;
	vector<pii>to;
	for(int i=0;i<8;i++)
		if(cango(x+dx[i], y+dy[i]))
			to.pb(mp(x+dx[i], y+dy[i]));
	sort(all(to), [](pii a,pii b){ return togo(a.F,a.S)<togo(b.F,b.S); });
	for(auto [xx,yy]:to){
		if(dfs(xx,yy,dep+1)){
			return true;
		}
	}
	vis[x][y] = 0;
	return false;
}

void solve(){
	int x,y;
	cin >> x >> y;
	dfs(x,y,1);
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++)
			cout << ans[j][i] << ' ';
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

