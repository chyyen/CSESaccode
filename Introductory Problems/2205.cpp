#pragma GCC optimize("Ofast")
#pragma loop_opt(on)

#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
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
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ld = long double;

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
// --------------------------------------**
const int N = 17;

int n;

int dp[N][(1<<N)];

int DP(int x,int dep){
	assert(x<(1<<dep));
	if(dep==1)
		return x;
	if(dp[dep][x]!=-1)
		return dp[dep][x]; 
	if(x<(1<<(dep-1)))
		return dp[dep][x] = DP(x,dep-1);
	else
		return dp[dep][x] = (1<<(dep-1))+DP((1<<dep)-x-1,dep-1);
}

void print(int x){
	string s = "";
	while(x){
		s += char('0'+(x%2));
		x >>= 1;
	}
	x = n-s.size();
	while(x--)
		s += '0';
	reverse(all(s));
	cout << s << '\n';
}

void solve(){
	cin >> n;
	mem(dp,-1);
	for(int i=0;i<(1<<n);i++)
		print(DP(i,n));
}

signed main(){
    Rushia_mywife
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

