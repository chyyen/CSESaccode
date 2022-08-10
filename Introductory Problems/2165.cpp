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
vector<pii>ans;

void hanoi(int l,int r,int a,int b,int c){
	if(l==r){
		ans.pb(mp(a,c));
		return;
	}
	hanoi(l+1,r,a,c,b);
	ans.pb(mp(a,c));
	hanoi(l+1,r,b,a,c);
}

void solve(){
	cin >> n;
	hanoi(1,n,1,2,3);
	cout << ans.size() << '\n';
	for(auto i:ans)
		cout << i.F << ' ' << i.S << '\n';
}

signed main(){
    Rushia_mywife
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

