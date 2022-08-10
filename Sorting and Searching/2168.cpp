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

mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);

#define Bint __int128
#define int long long
// --------------------------------------**
const int N = 2e5+10;

struct segment_tree{
	int seg[N<<3];
	void modify(int l,int r,int p,int val,int idx){
		if(l==r){
			seg[idx] += val;
			return;
		}
		int mid = (l+r)>>1;
		if(p<=mid)
			modify(l,mid,p,val,idx<<1);
		else 
			modify(mid+1,r,p,val,idx<<1|1);
		seg[idx] += val;
	}
	int query(int l,int r,int upbound,int idx){
		if(r==upbound)
			return seg[idx];
		int mid = (l+r)>>1, ans = 0;
		if(upbound>mid)
			ans += query(mid+1,r,upbound,idx<<1|1);
		ans += query(l,mid,min(mid,upbound),idx<<1);
		return ans;
	}
}sgt;

int n;

void solve(){
	cin >> n;
	vector<pair<pii,int>>a(n);
	vector<int>v;
	for(int i=0;i<n;i++){
		a[i].S = i;
		cin >> a[i].F.F >> a[i].F.S;
		v.pb(a[i].F.F);
		v.pb(a[i].F.S);
	}
	sort(all(a),[](pair<pii,int> x,pair<pii,int> y){
			if(x.F.F==y.F.F)
				return x.F.S>y.F.S;
			return x.F.F<y.F.F;
		}
	);
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	for(auto &i:a){
		i.F.F = lower_bound(all(v),i.F.F)-v.begin()+1;
		i.F.S = lower_bound(all(v),i.F.S)-v.begin()+1;
		sgt.modify(1,2*n,i.F.S,1,1);
	}
	int mx = 0;
	vector<int>can(n),be(n);
	for(int i=0;i<n;i++){
		if(sgt.query(1,2*n,a[i].F.S,1)>1)
			can[a[i].S] = 1;
		if(mx>=a[i].F.S)
			be[a[i].S] = 1;
		sgt.modify(1,2*n,a[i].F.S,-1,1);
		mx = max(mx,a[i].F.S);
	}
	for(auto i:can)
		cout << i << ' ';
	cout << '\n';
	for(auto i:be)
		cout << i << ' ';
	cout << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

