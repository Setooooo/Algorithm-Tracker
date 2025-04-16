//
// Created by beHe on 25-4-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//谭谭的树上研究
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,w;
    vector<vector<int>>graph;
    vector<vector<int>>father;
    vector<int>depth;
public:
    Solution(int n_,int w_):n(n_),w(w_),graph(n+1),father(n+1,vector<int>(20)),depth(n+1,0){
        int u,v;
        for(int i=1;i<n;++i)
            cin>>u>>v,graph[u].emplace_back(v),graph[v].emplace_back(u);
        dfs(1,0);
        ll ans=0;
        cin>>u>>v;
        for(int i=1;i<=n;++i){
            ans+=min(get_dis(i,u), get_dis(i,v));
        }
        cout<<ans*w;
    };
    void dfs(int x,int pre){
        father[x][0]=pre;
        depth[x]=depth[pre]+1;
        for(int i=1;i<20;++i)
            father[x][i]=father[father[x][i-1]][i-1];
        for(const auto &i:graph[x]){
            if(pre==i) continue;
            dfs(i,x);
        }
    }
    int LCA(int x,int y){
        if(depth[x]<depth[y]) swap(x,y);
        for(int i=19;i>=0;--i)
            if(depth[x]-(1<<i)>=depth[y]) x=father[x][i];
        if(x==y) return x;
        for(int i=19;i>=0;--i){
            if(father[x][i]!=father[y][i]) x=father[x][i],y=father[y][i];
        }
        return father[x][0];
    }
    int get_dis(int x,int y){
        int com=LCA(x,y);
        if(com==x||com==y){
            return abs(depth[x]-depth[y]);
        }else{
            return depth[x]-depth[com]+depth[y]-depth[com];
        }
    }
};


void solve()
{
    int n,w;
    cin>>n>>w;
    Solution one(n,w);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}