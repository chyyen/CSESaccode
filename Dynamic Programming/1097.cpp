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
const int N = 5010;

int n;
int a[N];
int pre[N];
int dp[N][N];

inline int sum(int l,int r){
	return pre[r]-pre[l-1];
}

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i] = pre[i-1]+a[i];
		dp[i][i] = a[i];
	}
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
			dp[i][i+len-1] = sum(i,i+len-1)-min(dp[i][i+len-2],dp[i+1][i+len-1]);
	cout << dp[1][n] << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

