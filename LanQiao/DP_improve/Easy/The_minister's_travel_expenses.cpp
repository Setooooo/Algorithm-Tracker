//
// Created by beHe on 25-3-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

ull ans=0;

void pre_dfs(int u,int pre,const vector<vector<pair<int,ull>>>&graph, vector<ull>&depth)
{
    ull min1=0,min2=0;
    for(const auto &[i,w]:graph[u]){
        if(i==pre) continue;
        pre_dfs(i,u,graph,depth);
        depth[u]=max(depth[u],depth[i]+w);
        if(min1<depth[i]+w){
            min2=min1,min1=depth[i]+w;
        }else if(min1>=depth[i]+w&&min2<depth[i]+w){
            min2=depth[i]+w;
        }
    }
    ans=max(ans,min1+min2);
}

void las_dfs(int u,int pre,const vector<vector<pair<int,ull>>>&graph, vector<ull>&depth)
{
    ull min1=0,min2=0;
    for(const auto &[i,w]:graph[u]){
        if(i==pre) continue;
        las_dfs(i,u,graph,depth);
        if(min1<depth[i]+w){
            min2=min1,min1=depth[i]+w;
        }else if(min1>=depth[i]+w&&min2<depth[i]+w){
            min2=depth[i]+w;
        }
    }
    ans=max(ans,min1+min2);
}

void solve()
{
    int n,x,y,w;
    cin>>n;
    vector<vector<pair<int,ull>>>graph(n+1);
    vector<ull>depth(n+1,0);

    for(int i=1;i<n;++i){
        cin>>x>>y>>w;
        graph[x].emplace_back(y,w),graph[y].emplace_back(x,w);
    }
    pre_dfs(1,0,graph,depth);
//    las_dfs(1,0,graph,depth);
    cout<<(ans*21+ans*ans)/2;
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