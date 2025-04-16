//
// Created by beHe on 25-3-24.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//旅行销售员
using namespace std;

using ll=long long;
using ull=unsigned long long;

//路径压缩并查集
struct Union{
    int siz;
    vector<int>father;
public:
    Union(int n):siz(n),father(n+1){
        for(int i=0;i<=n;++i) father[i]=i;
    }
    int get_father(int x){
        if(father[x]!=x)
            return father[x]=get_father(father[x]);
        else return x;
    }
    void merge(int x,int y){
        int fx= get_father(x);
        int fy= get_father(y);
        if(fx!=fy) father[fx]=fy;
    }
};
//Kruskal算法
class Solution{
    int n,m;
    struct Edge{
        int u,v,w;
    public:
        bool operator<(const Edge&ri)const{ return w>ri.w;}
    };
public:
    Solution(int n_,int m_):n(n_),m(m_) {
        int u,v,w;
        Union unio(n+1);
        vector<Edge>pq;
        for(int i=0;i<m;++i) cin>>u>>v>>w,pq.push_back({u,v,w});
        sort(pq.begin(),pq.end());
        int ans=-1,cnt=0,ed=pq.size();
        for(int i=ed-1;i>=0;--i) {
            if(cnt>=n-1) break;
            auto &[u,v,w]=pq[i];
            if(unio.get_father(u)==unio.get_father(v)) continue;
            ++cnt; unio.merge(u,v);
            ans=max(ans,w);
        }
        cout<<ans<<'\n';
    }
};
//Prim算法
class Solution2{
    int n,m;
    struct node{
        int u,w;
        bool operator<(const node&ri)const {
            return w>ri.w;
        }
    };
    vector<vector<node>>graph;
public:
    Solution2(int n_,int m_):n(n_),m(m_),graph(n+1) {
        int u,v,w;
        Union unio(n+1);
        for(int i=0;i<m;++i){
            cin>>u>>v>>w,graph[u].push_back({v,w}),graph[v].push_back({u,w});
        }
        bitset<100010>vis;
        vector<int>cal(n+1,1e8);
        priority_queue<node>pq;
        int cnt=0,ans=-1;
        pq.push({1,0});
        while(!pq.empty()&&cnt<n){
            auto [po,w]=pq.top(); pq.pop();
            if(vis[po]) continue; vis[po]=true,++cnt,ans=max(ans,w);
            for(const auto &[v,wei]:graph[po]){
                if(!vis[v]) pq.push({v,wei});
            }
        }
        cout<<ans<<'\n';
    }
};


void solve()
{
    int n,m;
    cin>>n>>m;
    Solution2 one(n,m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}