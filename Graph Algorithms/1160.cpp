#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int n,m;
int vis[N];
int circle[N], order[N], sz[N];
int root[N], dep[N];
int tbl[20][N];
vector<int>G[N];

int find_cir(int x,int cnt,int ord){
    vis[x] = cnt;
    order[x] = ord;
    for(auto i:G[x]){
        if(vis[i]){
            if(vis[i]==cnt)
                circle[x] = cnt;    
        }
        else if(find_cir(i,cnt,ord+1))
            circle[x] = cnt;
    }
    if(circle[x]){
        sz[cnt] = max(sz[cnt],ord+1);
        return 1;
    }
    return 0;
}

void build(int x,int px,int R){
    dep[x] = dep[px]+1;
    root[x] = R;
    for(int i=1;i<20;i++)
        tbl[i][x] = tbl[i-1][tbl[i-1][x]];
    for(auto i:G[x]){
        if(i==px||circle[i])
            continue;
        tbl[0][i] = x;
        build(i,x,R);
    }
}

int query(int x,int len){
    if(len<0)
        return 0;
    //cout << x << ' ' << len << " : ";
    for(int i=19;i>=0;i--){
        if((1<<i)<=len){
            x = tbl[i][x];
            len -= (1<<i);
        }
    }
    //cout << x << '\n';
    return x;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int u;
        cin >> u;
        G[u].push_back(i);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            cnt++, find_cir(i,cnt,0);
    for(int i=1;i<=n;i++)
        if(circle[i])
            build(i,i,i);
    while(m--){
        int a,b;
        cin >> a >> b;
        //cout << a << " : " << root[a] << ' ' << dep[a] << '\n';
        //cout << b << " : " << root[b] << ' ' << dep[b] << '\n';
        if(circle[root[a]]!=circle[root[b]]||dep[a]<dep[b])
            cout << -1 << '\n';
        else if(circle[a]&&circle[b])
            cout  << (order[a]-order[b]+sz[circle[a]])%sz[circle[a]] << '\n';
        else if(circle[b])     
            cout << ((order[root[a]]-order[b]+sz[circle[b]])%sz[circle[b]])+dep[a]-1 << '\n';
        else if(query(a,dep[a]-dep[b])==b)
            cout << dep[a]-dep[b] << '\n';
        else 
            cout << -1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}