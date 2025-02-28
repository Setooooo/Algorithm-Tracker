//
// Created by beHe on 25-3-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void dfs(int u,int pre,const vector<ll>&arr,const vector<vector<int>>&graph,vector<pair<ll,ll>>&dp)
{
    dp[u].second=arr[u];
    dp[u].first=0;
    for(const auto i:graph[u]){
        if(i==u) continue;
        dfs(i,u,arr,graph,dp);
        dp[u].first+=max(dp[i].first,dp[i].second);
        dp[u].second+=dp[i].first;
    }
}

void solve()
{
    int n,x,y;
    cin>>n;
    vector<ll>arr(n+1);
    for(int i=1;i<=n;++i) cin>>arr[i];
    vector<vector<int>>graph(n+1),rudu(n + 1);
    vector<pair<ll,ll>>dp(n+1);
    for(int i=1;i<n;++i)
        cin>>x>>y,graph[y].emplace_back(x),rudu[x].emplace_back(y);
    int root=1;
    for(int i=1;i<=n;++i)
        if(rudu[i].empty())
        {
            root=i;
            break;
        }
    dfs(root,0,arr,graph,dp);
    cout<<max(dp[root].first,dp[root].second);
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