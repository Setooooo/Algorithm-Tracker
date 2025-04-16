//
// Created by beHe on 25-3-27.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m;
    vector<ll>dist;
    vector<bool>vis;
    vector<vector<pair<int,ll>>>graph;
    vector<int>wihte;
    struct node{
        int po;ll w;
        bool operator<(const node&ri)const {
            return w>ri.w;
        }
    };
public:
    Solution(int n_,int m_):n(n_),m(m_),dist(n+1,2e10),vis(n+1,false),graph(n+1),wihte(n+1){
        int u,v,w;
        for(int i=1;i<=n;++i) cin>>wihte[i];
        wihte[1]=0;
        for(int i=0;i<m;++i) cin>>u>>v>>w,graph[u].push_back({v,w}),graph[v].push_back({u,w});
        priority_queue<node>pq;
        pq.push({1,dist[1]=0});
        while(!pq.empty()){
            int no=pq.top().po; pq.pop();
            if(vis[no]) continue; vis[no]=true;
            if(no==n) break;
            for(const auto &[next,wei]:graph[no]){
                if(vis[next]) continue;
                    if(dist[next]>dist[no]+wei+wihte[no]) pq.push({next,dist[next]=dist[no]+wei+wihte[no]});
            }
        }
        cout<<dist[n];
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    Solution one(n,m);
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