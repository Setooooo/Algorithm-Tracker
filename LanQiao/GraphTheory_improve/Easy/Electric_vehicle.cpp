//
// Created by beHe on 25-3-30.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//电动车
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m,cnt;
    ll ans;
    vector<vector<pair<ll,int>>>graph;
    bitset<200010>vis;
public:
    Solution(int n_,int m_):cnt(0),ans(0),m(m_),n(n_),graph(n+1),vis(false){
        int u,v; ll w;
        for(int i=0;i<m;++i)cin>>u>>v>>w,graph[u].push_back({w,v}),graph[v].push_back({w,u});
        priority_queue<pair<ll,int>>pq;
        pq.push({0,1});
        while(!pq.empty()&&cnt<n){
            auto [wei,x]=pq.top(); pq.pop();
            if(vis[x]) continue; vis[x]=true,++cnt,ans=max(ans,-wei);
            for(const auto [len,y]:graph[x]){
                if(vis[y]) continue; pq.push({-len,y});
            }
        }
        if(cnt==n)
            cout<<ans;
        else
            cout<<-1;
    };
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