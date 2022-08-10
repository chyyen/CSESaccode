#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7; 

int qpow(int x,int t){
	int res = 1;
	while(t){
		if(t&1)
			res = res*x%mod;
		t >>= 1;
		x = x*x%mod;
	}
	return res;
}

signed main(){
	int n;
	cin >> n;
	cout << qpow(2,n) << '\n';
}

