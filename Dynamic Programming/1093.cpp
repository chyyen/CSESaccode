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
const int N = 510;

int qpow(int x,int cnt){
	int res = 1;
	while(cnt){
		if(cnt&1)
			res = res*x%mod;
		x = x*x%mod;
		cnt >>= 1;
	}
	return res;
}

int n;
int dp[N*N];

void solve(){
	cin >> n;
	if((n*(n+1)/2)&1){
		cout << 0 << '\n';
		return;
	}
	dp[0] = dp[1] = 1;
	for(int i=2;i<=n;i++)
		for(int j=n*n;j>=0;j--)
			if(j>=i)
				dp[j] = (dp[j]+dp[j-i])%mod;
	cout << dp[n*(n+1)/4]*qpow(2,mod-2)%mod << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

