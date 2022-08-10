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

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
// --------------------------------------**

int n,w;

void solve(){
	cin >> n >> w;
	vector<int>a(n);
	for(auto &i:a)
		cin >> i;
	vector<pair<int,int>>dp(1<<n,mp(100,1e9+10));
	dp[0] = mp(1,0);
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)==0)
				continue;
			auto [x,y] = dp[i^(1<<j)];
			if(y+a[j]>w)
				x++, y = a[j];
			else
				y += a[j];
			dp[i] = min(dp[i],mp(x,y));
		}
	}
	cout << dp[(1<<n)-1].F << '\n'; 
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

