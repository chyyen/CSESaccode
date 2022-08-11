#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16;
const int N = 510;

int n,m;

struct Graph{
    struct edge{
        int to,rev,cap,not_rev;
        edge(int p1,int p2,int p3,int p4){
            rev = p2;
            cap = p3;
            to = p1;
            not_rev = p4;
        }
    };
    int dep[N];
    int iter[N];
    vector<edge>g[N];
    void addedge(int u,int v){
        g[u].push_back(edge(v,g[v].size(),1,1));
        g[v].push_back(edge(u,g[u].size()-1,0,0));
    }
    void bfs(){
        queue<int>que;
        que.push(1);
        dep[1] = 0;
        while(!que.empty()){
            auto x = que.front();
            que.pop();
            for(auto i:g[x]){
                if(dep[i.to]==-1&&i.cap){
                    que.push(i.to);
                    dep[i.to] = dep[x]+1;
                }
            }
        }
    }
    int dfs(int x,int fl){
        if(x==n)
            return fl;
        for(int &_=iter[x];_<g[x].size();_++){
            auto &i = g[x][_];
            if(dep[i.to]==dep[x]+1&&i.cap>0){
                int res = dfs(i.to,min(fl,i.cap));
                if(res>0){
                    i.cap -= res;
                    g[i.to][i.rev].cap += res;
                    return res;
                }
            }
        }
        return 0;
    }
    int Dinic(){
        int res = 0;
        while(1){
            fill(dep,dep+n+1,-1);
            fill(iter,iter+n+1,0);
            bfs();
            if(dep[n]==-1)
                break;
            int cur;
            while((cur = dfs(1,INF))>0)
                res += cur;
        }
        fill(iter,iter+1+n,0);
        return res;
    }
    void find_path(){
        vector<int>res;
        int now = 1;
        while(1){
            res.push_back(now);
            //cout << now << ' ';
            //cout.flush();
            if(now==n)
                break;
            for(int &_=iter[now];_<g[now].size();_++){
                auto &i = g[now][_];
                if(i.cap==0&&i.not_rev){
                    now = i.to;
                    i.cap = 1;
                    break;
                }
            }
        }
        //cout << endl;
        //cout.flush();
        cout << res.size() << '\n';
        for(auto i:res)
            cout << i << ' ';
        cout << '\n';
    }
}G;

void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G.addedge(u,v);
    }
    int ans = G.Dinic();
    cout << ans << '\n';
    while(ans--)
        G.find_path();
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}