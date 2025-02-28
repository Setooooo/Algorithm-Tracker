//
// Created by beHe on 25-3-6.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void dfs_pre(int u,int pre,vector<ull>&siz,const vector<vector<int>>&graph){
    for(const auto i:graph[u])
    {
        if(i==pre) continue;
        dfs_pre(i,u,siz,graph);
        siz[u]+=siz[i];
    }
}

void dfs_las(int u,int pre,vector<ull>&dp,vector<ull>&siz,const vector<vector<int>>&graph,const int & n)
{
    for(const auto i:graph[u]){
        if(i==pre) continue;
        dp[i]=dp[u]-siz[i]+(n-siz[i]);
        dfs_las(i,u,dp,siz,graph,n);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<ull>dp(n+1,0),siz(n+1,1);
    vector<vector<int>>graph(n+1);
    int x,y;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        graph[x].emplace_back(y),graph[y].emplace_back(x);
    }
    dfs_pre(1,0,siz,graph);
    for(int i=1;i<=n;++i) dp[1]+=siz[i];
    dp[1]-=n;
    dfs_las(1,0,dp,siz,graph,n);
    cout<<*min_element(dp.begin()+1,dp.end());
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