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
 
int n;
string ans; 
bitset<(1<<17)>vis;

void dfs(int x){
	vis[x] = 1;
	ans += (char)('0'+(x&1));
	if((x>>(n-1)))
		x -= (1<<(n-1));
	if(!vis[x<<1|1])
		dfs(x<<1|1);
	else if(!vis[x<<1])
		dfs(x<<1);
}

void solve(){
	cin >> n;
	for(int i=1;i<n;i++)
		ans += '0';
	dfs(0);
	cout << ans << '\n';
	//cout << ans.size() << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}
