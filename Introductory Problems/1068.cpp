#pragma GCC optimize("Ofast")
#pragma loop_opt(on)

#include<bits/stdc++.h>

#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using ld = long double;

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
int qpow(int x,int powcnt,int tomod){
	int res = 1;
	for(;powcnt;powcnt>>=1,x=(x*x)%tomod)
		if(1&powcnt)res = (res*x)%tomod;
	return (res%tomod);
}
int inv(int x){ return qpow(x,mod-2,mod); }
// --------------------------------------**

int n;

void solve(){
	cin >> n;
	cout << n << ' ';
	while(n!=1){
		if(n&1)
			n = 3*n+1;
		else
			n /= 2;
		cout << n << ' ';
	}
	cout << '\n';
}

signed main(){
    Rushia_mywife
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

