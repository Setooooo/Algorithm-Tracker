//
// Created by beHe on 25-3-28.
//
//魔法阵
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,k,m;
    vector<vector<pair<int,ll>>>graph;
    vector<vector<ll>>dist;
public:
    Solution(int n_,int k_,int m_):n(n_),k(k_),m(m_),
    graph(n),dist(n,vector<ll>(k+1,1e15)){
        int u,v,wei;
        for(int i=0;i<m;++i) cin>>u>>v>>wei,graph[u].push_back({v,wei}),graph[v].push_back({u,wei});
        queue<int>q;
        dist[0][0]=0;
        q.push(0);
        while(!q.empty()){
            int x=q.front(); q.pop();
            for(const auto &i:graph[x]){
                bool flag=false;
                auto &[y,w]=i;
                if(dist[y][0]>dist[x][0]+w){
                    dist[y][0]=dist[x][0]+w;
                    flag=true;
                }
                for(int j=1;j<=k;++j){
                    if(dist[y][j]>dist[x][j-1]){
                        dist[y][j]=dist[x][j-1];
                        flag=true;
                    }
                }
                if(dist[y][k]>dist[x][k]+w){
                    dist[y][k]=dist[x][k]+w;
                    flag=true;
                }
                if(flag) q.push(y);
            }
        }
        cout<<min(dist[n-1][k],dist[n-1][0]);
    };
};

void solve()
{
    int n,k,m;
    cin>>n>>k>>m;
    Solution one(n,k,m);
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