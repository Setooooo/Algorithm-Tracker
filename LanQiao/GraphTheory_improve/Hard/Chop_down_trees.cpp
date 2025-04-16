//
// Created by beHe on 25-3-30.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m;
    vector<vector<pair<int,int>>>graph;
    vector<vector<int>>father;
    vector<int>cnt;
    vector<pair<int,int>>query;
    vector<int>dep,s;
    int ans;
public:
    Solution(int n_,int m_):n(n_),m(m_),ans(-1),
    graph(n+1),father(n+1,vector<int>(20,0)),
    cnt(n+1,0),query(m),dep(n+1),s(n+1){
        int u,v;
        for(int i=1;i<n;++i) cin>>u>>v,graph[u].push_back({v,i}),graph[v].push_back({u,i});
        for(int i=0;i<m;++i) cin>>query[i].first>>query[i].second;
        dfs(1,0);
        for(const auto &[x,y]:query){
            ++cnt[x],++cnt[y];
            int cof= LCA(x,y);
            --cnt[cof],--cnt[cof];
        }
        final(1,0);
        cout<<ans;
    };
    void dfs(int x,int pre) {
        dep[x]=dep[pre]+1;
        father[x][0]=pre;
        for(int i=1;i<20;++i)
            father[x][i]=father[father[x][i-1]][i-1];
        for(const auto nex:graph[x]){
            if(nex.first == pre) continue;
            else {
                s[nex.first]=nex.second;
                dfs(nex.first, x);
            }
        }
    }
    int LCA(int x,int y) const {
        if(dep[x]<dep[y]) swap(x,y);
        for(int i=19;i>=0;--i){
            if(dep[x]-(1<<i)>=dep[y]) x=father[x][i];
        }
        if(x==y) return x;
        for(int i=19;i>=0;--i){
            if(father[x][i]!=father[y][i]) x=father[x][i],y=father[y][i];
        }
        return father[x][0];
    }
    int final(int x,int pre){

        for(const auto i:graph[x]){
            if(i.first==pre) continue;
            cnt[x]+=final(i.first,x);
        }
        if(cnt[x]==m)
            ans=max(ans,s[x]);
        return cnt[x];
    }
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