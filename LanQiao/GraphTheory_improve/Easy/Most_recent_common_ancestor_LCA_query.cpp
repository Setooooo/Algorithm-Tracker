//
// Created by beHe on 25-3-25.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//最近公共祖先LCA查询
using namespace std;

using ll=long long;
using ull=unsigned long long;

//倍增求LCA
class Solution{
    int n;
    vector<vector<int>>pa;
    vector<vector<int>>tree;
    vector<int>depth;
public:
    Solution(int n_):n(n_),pa(n+1,vector<int>(19,0)),tree(n+1),depth(n+1,0){
        int x,y;
        for(int i=1;i<n;++i){
            cin>>x>>y; tree[x].emplace_back(y),tree[y].emplace_back(x);
        }
        dfs(1,0);
        int q;
        cin>>q;
        while(q--){
            cin>>x>>y;
            cout<<LCA(x,y)<<'\n';
        }

    }
    void dfs(int x,int p){
        pa[x][0]=p;
        depth[x]=depth[p]+1;

        for(int i=1;i<19;++i)
            pa[x][i]=pa[pa[x][i-1]][i-1];

        for(const auto &i:tree[x]) if(i!=p) dfs(i,x);
    }

    int LCA(int u,int v) const {
        if(depth[u]<depth[v]) swap(u,v);
        for(int i=18;i>=0;--i){
            if(depth[u]-(1<<i)>=depth[v]) u=pa[u][i];
        }
        if(u==v) return u;
        for(int i=18;i>=0;--i){
            if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i];
        }
        return pa[u][0];
    }
};

//Tarjan离线求LCA
class Solution2{
    int n;
    struct Query{
        int nod,id;
    };
    vector<vector<Query>>query;
    vector<int>pre;
    vector<vector<int>>graph;
    vector<bool>vis;
    vector<int>ans;
public:
    Solution2(int n_):n(n_),query(n+1),pre(n+1),graph(n+1),vis(n+1,false){
        for(int i=0;i<=n;++i) pre[i]=i;
        int u,v;
        for(int i=1;i<n;++i) cin>>u>>v,graph[u].emplace_back(v),graph[v].emplace_back(u);
        int q;
        cin>>q;
        for(int i=0;i<q;++i) {
            cin>>u>>v;
            query[u].push_back({v,i}) , query[v].push_back({u,i});
        }
        ans.resize(q+1,0);
        dfs(1,0);
        for(int i=0;i<q;++i)
            cout<<ans[i]<<'\n';
    }
    void dfs(int u,int pa) {
        vis[u]=true;
        for(const auto &next:graph[u]){
            if(next == pa) continue;
            dfs(next,u);
            pre[next]=u;
        }
        for(auto [y,id]:query[u]){
            if(vis[y]) {
                while(pre[y]!=y) y=pre[y];
                ans[id]=y;
            }
        }
    }
};



void solve()
{
    int n;
    cin>>n;
    Solution2 one(n);
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