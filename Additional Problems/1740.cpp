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
const int N = 1e6+10;

struct segtree{
	int tr[N<<2];
	void modify(int p,int v){
		for(p+=2*N;p;p>>=1)
			tr[p] += v;
	}
	int query(int l,int r){
		r++;
		int res = 0;
		for(l+=2*N,r+=2*N;l<r;l>>=1,r>>=1){
			if(l&1)
				res += tr[l++];
			if(r&1)
				res += tr[--r];
		}
		return res;
	}
}sgt;

int n;

void solve(){
	cin >> n;
	vector<pair<pii,int>>hor,ver;
	for(int i=0,a,b,c,d;i<n;i++){
		cin >> a >> b >> c >> d;
		if(a>c)
			swap(a,c);
		if(b>d)
			swap(b,d);
		if(a==c)
			ver.pb(mp(mp(b+N,d+N),a+N));
		else
			hor.pb(mp(mp(a+N,c+N),b+N));
	}
	sort(all(hor), [](pair<pii,int>a,pair<pii,int>b){
		return a.S<b.S;
	});
	sort(all(ver), [](pair<pii,int>a,pair<pii,int>b){
		return a.F.S<b.F.S;	
	});
	priority_queue<pii>pq;
	int ans = 0;
	while(!hor.empty()){
		vector<pii>seg;
		int y = hor.back().S;
		while(!hor.empty() && hor.back().S==y){
			seg.pb(hor.back().F);
			hor.pob();
		}
		while(!ver.empty() && ver.back().F.S>=y){
			if(ver.back().F.F<=y){
				sgt.modify(ver.back().S,1);
				pq.push(mp(ver.back().F.F,ver.back().S));
			}
			ver.pob();
		}
		while(!pq.empty() && pq.top().F>y){
			sgt.modify(pq.top().S,-1);
			pq.pop();
		}
		for(auto [l,r]:seg)
			ans += sgt.query(l,r);
	}
	cout << ans << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

