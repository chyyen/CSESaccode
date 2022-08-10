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
const int N = 1010;

int n;
int a[N][N];
int dp[N][N];

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;
			cin >> x;
			a[i][j] = (x=='*');
		}
	}
	dp[1][1] = 1^a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j&&i==1)
				continue;
			if(a[i][j])
				continue;
			dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	cout << dp[n][n] << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

