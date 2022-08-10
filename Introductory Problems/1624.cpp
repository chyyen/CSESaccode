#include<bits/stdc++.h>
using namespace std;

const int CONST = 20;
int r[8],s1[40],s2[40];
string board[8];

int dfs(int x){
	if(x==8)
		return 1;
	int ans = 0;
	for(int i=0;i<8;i++){
		if(!r[i] && !s1[i-x+CONST] && !s2[i+x] && board[x][i]!='*'){
			r[i] = 1, s1[i-x+CONST] = 1, s2[i+x] = 1;
			ans += dfs(x+1);
			r[i] = 0, s1[i-x+CONST] = 0, s2[i+x] = 0;
		}
	}
	return ans;
}

void solve(){
	for(int i=0;i<8;i++)
		cin >> board[i];
	cout << dfs(0) << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}

