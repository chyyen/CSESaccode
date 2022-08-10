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

int x,y;

void solve(){
	cin >> x >> y;
	if(x>=y){
		if(x&1)
			cout << (x-1)*(x-1)+y << '\n';
		else
			cout << x*x-y+1 << '\n';
	}
	else{
		if(y&1)
			cout << y*y-x+1 << '\n';
		else
			cout << (y-1)*(y-1)+x << '\n';
	}
}

signed main(){
    Rushia_mywife
    int t = 1; 
    cin >> t;
    while(t--)
        solve();
}

