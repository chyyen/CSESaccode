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

int n;
string s;

void solve(){
	cin >> s;
	n = s.size();
	vector<int>cnt(26,0);
	for(auto i:s)
		cnt[i-'A']++;
	if(n&1){
		int odd = -1;
		for(int i=0;i<26;i++){
			if(odd>=0&&cnt[i]&1){
				cout << "NO SOLUTION\n";
				return;
			}
			if(cnt[i]&1)
				odd = i;
		}
		for(int i=0;i<26;i++){
			int x = cnt[i]/2;
			while(x--)
				cout << char(i+'A');
		}
		cout << char(odd+'A');
		for(int i=25;i>=0;i--){
			int x = cnt[i]/2;
			while(x--)
				cout << char(i+'A');
		}
	}
	else{
		for(int i=0;i<26;i++){
			if(cnt[i]&1){
				cout << "NO SOLUTION\n";
				return;
			}
		}
		for(int i=0;i<26;i++){
			int x = cnt[i]/2;
			while(x--)
				cout << char(i+'A');
		}
		for(int i=25;i>=0;i--){
			int x = cnt[i]/2;
			while(x--)
				cout << char(i+'A');
		}
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

