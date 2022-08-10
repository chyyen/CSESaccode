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

struct interval{
	int l,r,len,sum,ans;
	interval(){}
	interval(int _l,int _r,int s,int a){
		l = _l, r = _r, sum = s, len = r-l+1, ans = a;
	}
};

struct segtree{
	interval seg[N<<2];
	int tag[N<<2];
	interval merge(interval a,interval b){
		return interval(a.l, b.r, a.sum+b.sum, a.ans+a.sum*b.len+b.ans);
	}
	void addtag(int idx,int v){
		tag[idx] += v;
		seg[idx].sum += v*seg[idx].len;
		seg[idx].ans += v*seg[idx].len*(seg[idx].len+1)/2;
	}
	void push(int idx){
		addtag(idx<<1, tag[idx]);
		addtag(idx<<1|1, tag[idx]);
		tag[idx] = 0;
	}
	void build(int l,int r,int idx,int *a){
		if(l==r){
			seg[idx] = interval(l,r,a[l]-a[l-1],a[l]-a[l-1]);
			return;
		}
		int mid = (l+r)>>1;
		build(l,mid,idx<<1,a);
		build(mid+1,r,idx<<1|1,a);
		seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
	}
	void modify(int l,int r,int ql,int qr,int v,int idx){
		if(ql==l && qr==r){
			addtag(idx,v);
			return;
		}
		if(tag[idx])
			push(idx);
		int mid = (l+r)>>1;
		if(qr<=mid)
			modify(l,mid,ql,qr,v,idx<<1);
		else if(ql>mid)
			modify(mid+1,r,ql,qr,v,idx<<1|1);
		else
			modify(l,mid,ql,mid,v,idx<<1), modify(mid+1,r,mid+1,qr,v,idx<<1|1);
		seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
	}
	interval query(int l,int r,int ql,int qr,int idx){
		if(ql==l && qr==r)
			return seg[idx];
		if(tag[idx])
			push(idx);
		int mid = (l+r)>>1;
		if(qr<=mid)
			return query(l,mid,ql,qr,idx<<1);
		else if(ql>mid)
			return query(mid+1,r,ql,qr,idx<<1|1);
		return merge(
			query(l,mid,ql,mid,idx<<1),
			query(mid+1,r,mid+1,qr,idx<<1|1)
		);
	}
}sgt;

int n,q;
int a[N];

void solve(){
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sgt.build(1,n,1,a);
	while(q--){
		int op,l,r;
		cin >> op >> l >> r;
		if(op==1){
			sgt.modify(1,n,l,r,1,1);
			if(r<n)
				sgt.modify(1,n,r+1,r+1,-(r-l+1),1);
		}
		else
			cout << sgt.query(1,n,1,r,1).ans-(l>1 ? sgt.query(1,n,1,l-1,1).ans : 0) << '\n';
	}
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

