//
// Created by beHe on 25-3-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//染色时间
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m;
    vector<vector<int>>graph;
    vector<vector<int>>dist;
    vector<vector<bool>>vis;
    struct node{
        int x,y,t;
        bool operator<(const node&ri) const { return t>ri.t;}
    };
    static int dx[],dy[];
public:
    Solution(int n_,int m_):n(n_),m(m_),
    graph(n+1,vector<int>(m+1)),
    dist(n+1,vector<int>(m+1,1e7)),
    vis(n+1,vector<bool>(m+1)){

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) cin>>graph[i][j];
    priority_queue<node>pq;
    pq.push({1,1,dist[1][1]=graph[1][1]});
    while(!pq.empty()){
        auto [x,y,w]=pq.top(); pq.pop();
        if(vis[x][y]) continue; vis[x][y]=true;
        int nx=x,ny=y;
        for(int i=0;i<4;++i){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>n||nx<1||ny>m||ny<1||vis[nx][ny]) continue;
            if(dist[nx][ny]>dist[x][y]+graph[nx][ny])
                pq.push({nx,ny,dist[nx][ny]=dist[x][y]+graph[nx][ny]});
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) ans=max(ans,dist[i][j]);
    cout<<ans;
    };
};
int Solution::dx[] = {-1, 1, 0, 0};
int Solution::dy[] = {0, 0, -1, 1};


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