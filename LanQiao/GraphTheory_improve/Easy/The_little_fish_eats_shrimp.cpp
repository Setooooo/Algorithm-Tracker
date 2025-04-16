//
// Created by beHe on 25-3-24.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//小鱼吃虾米
using namespace std;

using ll=long long;
using ull=unsigned long long;


class Solution{
    int n,m,k;
    struct edge{
        int po;ll w;
        bool operator<(const edge&right)const{
            return w>right.w;
        }
    };
    vector<vector<edge>>graph;
    vector<int>is_brin;
    vector<ll>dis;
public:
    Solution(int n_,int m_,int k_):n(n_),m(m_),k(k_),graph(n+1),dis(n+1,2e18){
        int u,v,w;
        for(int i=0;i<k;++i) cin>>w,is_brin.emplace_back(w);
        for(int i=0;i<m;++i) cin>>u>>v>>w,graph[u].push_back({v,w});
        //添加虚拟源点
        for(const auto &i:is_brin){
            graph[0].push_back({i,0});
        }
        dijkstra(0);
        cout<<(dis[1]==(ll)2e18?-1:dis[1])<<'\n';
    }

    void dijkstra(int point){
        bitset<(int)(2e4+10)>vis;
        priority_queue<edge>pq;
        pq.push({point,dis[point]=0});
        while(!pq.empty()){
            int x=pq.top().po; pq.pop();
            if(vis[x]) continue;  vis[x]=true;
            for(const auto &[u,w]:graph[x])
                if(dis[u]>w+dis[x]) pq.push({u,dis[u]=w+dis[x]});
        }
    }
};


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    Solution one(n,m,k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}