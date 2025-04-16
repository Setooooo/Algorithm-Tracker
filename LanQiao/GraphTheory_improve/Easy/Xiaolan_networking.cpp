//
// Created by beHe on 25-3-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//小蓝组网
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
        int n,m;
        vector<vector<ll>>graph;
public:
    Solution(int n_,int m_):n(n_),m(m_),graph(n+1,vector<ll>(n+1,2e15)){
        int x,y;
        for(int i=1;i<=n;++i) graph[i][i]=0;
        for(int i=0;i<m;++i) cin>>x>>y,graph[x][y]=1,graph[y][x]=1;
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        ll ans=0; bool flag=false;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                if(graph[i][j]!=2e15)
                    ans=max(graph[i][j],ans);
                else{
                    flag=true;
                }
            }
        if(flag) cout<<"NO\n"<<ans;
        else cout<<"YES\n"<<ans;
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