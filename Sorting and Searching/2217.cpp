#include<bits/stdc++.h>

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
using pii = pair<long long,long long>;
using ld = long double;

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
// --------------------------------------**
const int N = 2e5+10;

int n,m;
int need[N];
int pos[N];
int a[N];

void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	pos[0] = pos[n+1] = 1e9+10;
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(pos[i]<pos[i-1])
			need[i] = 1, ans++;
	while(m--){
		int x,y;
		cin >> x >> y;
		int xx = a[x], yy = a[y];
		swap(a[x],a[y]);
		swap(pos[xx],pos[yy]);
		vector<int>tmp;
		for(int i=-1;i<=1;i++)
			tmp.pb(xx+i), tmp.pb(yy+i);
		sort(all(tmp));
		tmp.resize(unique(all(tmp))-tmp.begin());
		for(auto i:tmp){
			ans -= need[i];
			need[i] = (pos[i]<pos[i-1]);
			ans += need[i];
		}
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

