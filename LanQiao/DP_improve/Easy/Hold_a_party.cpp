//
// Created by beHe on 25-3-6.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void pre_dfs(int u,int pre, vector<int>&siz,const vector<vector<int>>&graph)
{
    for(const auto i:graph[u]){
        if(i==pre) continue;
        pre_dfs(i,u,siz,graph);
        siz[u]+=siz[i];
    }
}

void las_dfs(int u,int pre,
             vector<int>&siz,
             const vector<vector<int>>&graph,
             vector<pair<ull,int>>&dp,
             const int sum_peo)
{
    dp[u].second=u;
    for(const auto i:graph[u]){
        if(i==pre) continue;
        dp[i].first=dp[u].first-siz[i]+(sum_peo-siz[i]);
        las_dfs(i,u,siz,graph,dp,sum_peo);
    }
}


void solve()
{
    int n,k,sum_peo=0,x,y;
    cin>>n>>k;
    vector<int>siz(n+1);
    vector<vector<int>>graph(n+1);
    vector<pair<ull,int>>dp(n+1);
    for(int i=1;i<=n;++i) cin>>siz[i];
    for(int i=1;i<n;++i) cin>>x>>y,graph[x].emplace_back(y),graph[y].emplace_back(x);
    sum_peo=accumulate(siz.begin()+1,siz.end(),0);
    pre_dfs(1,0,siz,graph);
    for(int i=1;i<=n;++i) dp[1].first+=siz[i];
    dp[1].first-=siz[1];
    las_dfs(1,0,siz,graph,dp,sum_peo);
    sort(dp.begin()+1,dp.end(),
         [](const pair<ull,int>&a,const pair<ull,int>&b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    });
    cout<<dp[k].second;
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