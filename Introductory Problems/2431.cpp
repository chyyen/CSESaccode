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

int n;
vector<int>tbl;

void build(){
	tbl.pb(0);
	tbl.pb(9);
	for(int i=0;i<=18;i++)
		tbl.pb(tbl.back()*10+9);
}

string trans(int x){
	string ans = "";
	while(x){
		ans += char((x%10)+'0');
		x /= 10;
	}
	reverse(all(ans));
	return ans;
}

void solve(){
	cin >> n;
	int dig = upper_bound(all(tbl),n)-tbl.begin()-1;
	n -= tbl[dig];
	int x = (n-1)/(dig+1);
	int st = 1;
	for(int i=0;i<dig;i++)
		st *= 10;
	int re = n%(dig+1)-1;
	re = (re+dig+1)%(dig+1);
	string ans = trans(st+x);
	cout << ans[re] << '\n';
	cout << dig << '\n';
}

signed main(){
    Rushia_mywife
    build();
	int t = 1; 
    cin >> t;
    while(t--)
        solve();
}

