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

int n;
int dp[N];

void solve(){
	cin >> n;
	dp[0] = 1;
	for(int i=0;i<n;i++){
		int w;
		cin >> w;
		for(int j=N-1;j>=w;j--)
			dp[j] |= dp[j-w];
	}
	vector<int>ans;
	for(int i=1;i<N;i++)
		if(dp[i])
			ans.pb(i);
	cout << ans.size() << '\n';
	for(auto i:ans)
		cout << i << ' ';
	cout << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

