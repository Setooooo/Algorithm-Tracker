//
// Created by beHe on 25-3-23.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//Little_E_s_Highway

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll M=2e3+10,N=1e3+10,inf=1e9;
ll n,m;

struct Edge{
    ll u,v,w;
};
vector<Edge>ed;
struct Node{
    ll x,w;
    bool operator<(const Node&right)const{
        return w>right.w;
    }
};
vector<vector<Node>>g(N);

ll h[N];
bool BellmanFord( ){
    for(int i=1;i<=n;++i) h[i]=inf;
    for(int i=1;i<=n;++i){
        for(const auto &[u,v,w]:ed){
            if(h[u]==inf)continue;
            if(h[u]+w<h[v]) h[v]=h[u]+w;
        }
    }
    for(const auto &[u,v,w]:ed){
        if(h[u]==inf)continue;
        if(h[u]+w<h[v]) return false;
    }
    return true;
}

ll dis[N][N];

void dijkstra(int st){
    static ll d[N];
    for(int i=1;i<=n;++i) d[i]=inf;
    priority_queue<Node> pq;
    bitset<N>vis;
    pq.emplace(st,d[st]=0);
    while(!pq.empty()){
        auto [v,w]=pq.top();pq.pop();
        if(vis[v]) continue;
        vis[v]=true;
        for(const auto &[u,wei]:g[v]){
            if(d[u]>wei+w) pq.emplace(u,d[u]=wei+w);
        }
    }
    for(int i=1;i<=n;++i) {
        if(d[i]==inf) dis[st][i]=d[i];
        else dis[st][i]=d[i] - h[st] +h[i];
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        ll u,v,w; cin>>u>>v>>w;
        ed.emplace_back(u,v,w);
        g[u].emplace_back(v,w);
    }
    for(int i=1;i<=n;++i) ed.emplace_back(0,i,0);

    if(!BellmanFord()) {
        cout<<-1<<'\n';
        return;
    }

    for(int i=1;i<=n;++i){
        for(auto &[y,w]:g[i]){
            w= w + h[i]-h[y];
        }
    }

    for(int i=1;i<=n;++i){
        dijkstra(i);
    }
    for(int i=1;i<=n;++i)
    {
        ll ans=0;
        for(int j=1;j<=n;++j) ans += 1LL*j*dis[i][j];
        cout<<ans<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}