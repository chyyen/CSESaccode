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
const int N = 2e5+10;

int n;
pair<pii,int> a[N];
vector<int>v;

void dis(){
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	for(int i=0;i<n;i++){
		a[i].F.F = lower_bound(all(v),a[i].F.F)-v.begin()+1;
		a[i].F.S = lower_bound(all(v),a[i].F.S)-v.begin()+1;
	}
}

void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].F.F >> a[i].F.S >> a[i].S;
		v.pb(a[i].F.F);
		v.pb(a[i].F.S);
	}
	dis();
	sort(a,a+n,[](pair<pii,int> x,pair<pii,int> y){
			return x.F.S<y.F.S;
		}
	);
	int ptr = 0;
	vector<int>dp(n*3);
	for(int i=1;i<3*n;i++){
		dp[i] = dp[i-1];
		while(ptr<n&&a[ptr].F.S==i){
			dp[i] = max(dp[i], dp[a[ptr].F.F-1]+a[ptr].S);
			ptr++;
		}
	}
	cout << dp.back() << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}
	
