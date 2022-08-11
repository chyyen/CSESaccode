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
const int N = 2e5+10;

int n;

void solve(){
	cin >> n;
	vector<int>a(n);
	for(auto &i:a)
		cin >> i;
	auto owo = [](vector<int>a,int h) -> vector<int> {
		vector<int>res;
		int cur = 0;
		for(int i=0;i<(1<<h);i++)
			cur ^= a[i];
		res.pb(cur);
		for(int i=(1<<h);i<a.size();i++){
			cur ^= (a[i]^a[i-(1<<h)]);
			res.pb(cur);
		}
		return res;
	};
	while(n>1){
		int h = __lg(n);
		a = owo(a,h);
		n = n-(1<<h)+1;	
	}
	cout << a.back() << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

