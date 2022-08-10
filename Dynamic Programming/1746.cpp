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

int n,m;
int a[N];
int dp[N][110];

void solve(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(a[0])
		dp[0][a[0]] = 1;
	else
		for(int i=1;i<=m;i++)
			dp[0][i] = 1;
	for(int i=0;i<n;i++){
		//cout << i << " : ";
		for(int j=1;j<=m;j++){
			//cout << dp[i][j] << ' ';
			if(a[i]&&a[i]!=j)
				continue;
			if(j!=1)
				dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
			if(j<m)
				dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
			dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
		}
		//cout << '\n';
	}
	if(a[n-1])
		cout << dp[n-1][a[n-1]] << '\n';
	else{
		int ans = 0;
		for(int i=1;i<=m;i++)
			ans = (ans+dp[n-1][i])%mod;
		cout << ans << '\n';
	}	
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

