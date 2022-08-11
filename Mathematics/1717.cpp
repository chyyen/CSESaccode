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
const int N = 1e6+10;

int n;
int fac[N];

void build(){
	fac[0] = 1;
	for(int i=1;i<N;i++)
		fac[i] = fac[i-1]*i%mod;
}

int C(int x,int y){
	auto div = [&](int x) -> int {
		int res = 1,t = mod-2;
		while(t){
			if(t&1)
				res = res*x%mod;
			x = x*x%mod;
			t >>= 1;	
		}
		return res;
	};
	return (fac[x]*div(fac[x-y])%mod)*div(fac[y])%mod;
}

void solve(){
	build();
	cin >> n;
	int ans = 0;
	for(int i=0;i<=n;i++){
		if(i&1)
			ans = (ans-(C(n,i)*fac[n-i]%mod)+mod)%mod;
		else
			ans = (ans+(C(n,i)*fac[n-i]%mod))%mod;
	}
	cout << ans << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

