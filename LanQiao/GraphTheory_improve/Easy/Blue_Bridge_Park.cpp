//
// Created by beHe on 25-3-18.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//蓝桥公园
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n;
    vector<vector<ll>>graph;
public:
    Solution(int n_):n(n_),graph(n+1,vector<ll>(n+1,2e18)){
        ll m,q,u,v,w;
        cin>>m>>q;
        for(int i=1;i<=n;++i) graph[i][i]=0;
        for(int i=0;i<m;++i){
            cin>>u>>v>>w; graph[u][v]=graph[v][u]=min(graph[u][v],w);
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
        for(int i=0;i<q;++i){
            cin>>u>>v;
            cout<<(graph[u][v]>=(ll(2e18))?-1:graph[u][v])<<'\n';
        }
    }
};


void solve()
{
    int n;
    cin>>n;
    Solution se(n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\download\1121.in)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}