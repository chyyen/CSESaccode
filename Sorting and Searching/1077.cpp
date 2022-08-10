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

struct dynamic_segment_tree{
	int cnt = 0;// root : 0
	vector<pair<int,int>>seg;
	vector<int>lch;
	vector<int>rch;
	void modify(int l,int r,int p,int val,int idx){
		if(l==r){
			seg[idx].F += val;
			seg[idx].S += val/abs(val);
			return;
		}
		int mid = (l+r)>>1;
		if(p<=mid){
			if(lch[idx]==-1)
				lch[idx] = ++cnt;
			modify(l,mid,p,val,lch[idx]);
		}
		else{
			if(rch[idx]==-1)
				rch[idx] = ++cnt;
			modify(mid+1,r,p,val,rch[idx]);
		}
		seg[idx].F += val;
		seg[idx].S += val/abs(val);
	}
	pair<int,int> query(int l,int r,int upbound,int idx){
		if(l==upbound)
			return seg[idx];
		int mid = (l+r)>>1;
		pii ans = mp(0,0);
		if(rch[idx]!=-1){
			auto x = query(mid+1,r,max(upbound,mid+1),rch[idx]);
			ans.F += x.F;
			ans.S += x.S;
		}
		if(upbound<=mid&&lch[idx]!=-1){
			auto x = query(l,mid,upbound,lch[idx]);
			ans.F += x.F;
			ans.S += x.S;
		}
		return ans;
	}
	dynamic_segment_tree(int n){
		seg.resize(n*32);
		lch.resize(n*32,-1);
		rch.resize(n*32,-1);
	}
};

int n,k;
int a[N];

void solve(){
	cin >> n >> k;
	dynamic_segment_tree sgt(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
	int sum = 0;
	for(int i=0;i<k-1;i++){
		rbtree.insert(a[i]);
		sgt.modify(1,mod,a[i],a[i],0);
		sum += a[i];
	}
	for(int i=k-1;i<n;i++){
		sum += a[i];
		rbtree.insert(a[i]);
		sgt.modify(1,mod,a[i],a[i],0);
		int mid = *rbtree.find_by_order(k/2);
		auto x = sgt.query(1,mod,mid,0);
		cout << x.F-x.S*mid+(k-x.S)*mid-sum+x.F << ' ';
		sum -= a[i+1-k];
		sgt.modify(1,mod,a[i+1-k],-a[i+1-k],0);
		rbtree.erase(prev(rbtree.lower_bound(a[i+1-k])));
	}
	cout << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

