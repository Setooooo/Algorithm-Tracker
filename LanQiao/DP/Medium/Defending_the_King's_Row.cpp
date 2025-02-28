//
// Created by beHe on 25-3-4.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=2e5+10;

vector<vector<int>>dp(N,vector<int>(2,0));
vector<vector<int>>graph(N);

void dfs(int u,int v){
    int sumfang=0,sumbufang=0;
    for(const auto i:graph[u])
    {
        if(i==v) continue;
        dfs(i,u);
        sumfang+=dp[i][1];
        sumbufang+=min(dp[i][0],dp[i][1]);
    }
    dp[u][0]=sumfang;
    dp[u][1]=sumbufang+1;
}


void solve()
{
    int n;
    cin>>n;
    int x,y;
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        graph[x].emplace_back(y);graph[y].emplace_back(x);
    }
    dfs(1,0);
    cout<<min(dp[1][1],dp[1][0]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\download\4503.in)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}