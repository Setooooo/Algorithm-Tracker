//
// Created by beHe on 25-3-6.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=3e5+10;
int res_depth[N],p,ans;

void preuse(int u,int pre,vector<int>&depth,const vector<vector<int>>&graph){
    for(const auto i:graph[u])
    {
        if(i==pre) continue;
        preuse(i,u,depth,graph);
        depth[u]=max(depth[u],depth[i]+1);
    }
}

void dfs(int u,int pre,const vector<int>&depth,const vector<vector<int>>&graph)
{
    int depone=0,detwo=0;
    for(const auto i:graph[u]){
        if(i==pre) continue;
        dfs(i,u,depth,graph);
        if(depone<depth[i])
            detwo=depone,depone=depth[i];
        else if(depone>=depth[i]&&detwo<depth[i])
            detwo=depth[i];
    }
    ans=max(depone+detwo+1,ans);
}

void onedfs(int u,int pre,vector<int>&depth,const vector<vector<int>>&graph)
{
    int minn1=0,minn2=0;
    for(const auto i:graph[u]){
        if(i==pre) continue;
        onedfs(i,u,depth,graph);
        depth[u]=max(depth[i]+1,depth[u]);
        if(minn1<depth[i])
            minn2=minn1,minn1=depth[i];
        else if(minn2<depth[i])
            minn2=depth[i];
    }
    ans=max(ans,minn2+minn1+1);
}

void solve()
{
    int n,x,y;
    cin>>n;
    vector<int>depth(n+1,1);
    vector<vector<int>>graph(n+1);
    for(int i=1;i<n;++i){
        cin>>x>>y;
        graph[y].emplace_back(x),graph[x].emplace_back(y);
    }
//    preuse(1,0,depth,graph);
//    dfs(1,0,depth,graph);
    onedfs(1,0,depth,graph);
    cout<<ans-1;
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