#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
 
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))
 
using namespace std;
//using namespace __gnu_pbds;
using pii = pair<long long,long long>;
using ld = long double;
using ll = long long;
 
mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());
 
const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);
 
#define Bint __int128
#define int long long
/* ----------------------------------------  */
 
int n;

void solve(){
	cin >> n;
	auto calc = [&](int x) -> int{
		int res = 0;
		for(int i=1;i<=n;i++){
			int c = x/i;
			if(c*i==x)
				c--;
			res += min(n,c);
		}
		return res;
	};
	int l = 1,r = n*n;
	while(l<r){
		int mid = (l+r)>>1;
		int res = calc(mid);
		if(res>=n*n/2+1)
			r = mid-1;
		else
			l = mid;
		if(l+1==r){
			if(calc(r)>=n*n/2+1)
				r = l;
			else
				l = r;
		}
	}
	cout << l << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

