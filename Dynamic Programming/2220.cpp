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
// --------------------------------------*

int L,R;
int dp[20][10];
int sum[20];

int owo(int n){
	if(n<0)
		return 0;
	if(n<10)
		return n+1;
	int p = 1,dig = 0;
	while(n/p>=10)
		p *= 10, dig++;
	int ans = 1,cur = 0;
	for(int i=0;i<dig;i++)
		ans +=sum[i]-dp[i][0];
	while(dig>=0){
		for(int i=0;i<n/p;i++)
			if(i!=cur%10)
				ans += dp[dig][i];
		if(n/p==cur%10)
			break;
		dig--;
		cur = cur*10+n/p;
		n %= p;
		p /= 10;
	}
	if(dig<0)
		ans++;
	return ans;
}

void solve(){
	for(int i=0;i<10;i++)
		dp[0][i] = 1;
	sum[0] = 10;
	for(int i=1;i<19;i++){
		for(int j=0;j<10;j++){
			dp[i][j] = sum[i-1]-dp[i-1][j], sum[i] +=  dp[i][j];
			//cout << dp[i][j] << ' ';
		}
		//cout << '\n';
	}
	cin >> L >> R;
	//cout << R << " : " << owo(R) << '\n';
	//cout << L-1 << " : " << owo(L-1) << '\n';
	cout << owo(R)-owo(L-1) << '\n';
}

signed main(){
    Daredemo_Daisuki
    int t = 1; 
    //cin >> t;
    while(t--)
        solve();
}

