//
// Created by beHe on 25-3-4.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void dfs(int u,vector<int>&dp,const vector<vector<int>>&graph) {
    int maxx = 1;
    for (const auto i: graph[u]) {
        if(u==i) continue;
        dfs(i, dp, graph);
        maxx = max(maxx, dp[i]);
    }
    dp[u] = maxx+graph[u].size();
}

void solve()
{
    int n,x;
    cin>>n;
    vector<vector<int>>graph(n+1);
    vector<int>dp(n+1,0);
    for(int i=2;i<=n;++i)
    {
        cin>>x,graph[x].emplace_back(i);
    }
    dfs(1,dp,graph);
    cout<<dp[1]-1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}