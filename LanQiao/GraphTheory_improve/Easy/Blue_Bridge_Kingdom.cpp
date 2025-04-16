//
// Created by beHe on 25-3-18.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//蓝桥王国
using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=3e5+10;

class Solution{
    int n,m;
    vector<vector<pair<int,ll>>>graph;
    vector<ll>distan;
    bitset<N>vis;
    class cmp{
    public:
        bool operator()(const pair<int,ll>&a,const pair<int,ll>&b){
            return a.second>b.second;
        }
    };
    priority_queue<pair<int,ll>,vector<pair<int,ll>>,cmp>pq;
public:
    Solution(int n_,int m_): n(n_), m(m_), graph(n+1), pq(cmp{}), vis(false), distan(n + 1, 2e18){
        int u,v,w;
        for(int i=0;i<m;++i){
            cin>>u>>v>>w;
            graph[u].emplace_back(v,w);
        }
        pq.emplace(1, distan[1]=0);
        while (!pq.empty()){
            auto [x,y]=pq.top(); pq.pop();
            if(vis[x]) continue;
            vis[x]=true;
            for(const auto &[next,leng]:graph[x]){

                if(distan[x] + leng < distan[next]) {
                    pq.emplace(next,distan[next]=distan[x]+leng);
                }
            }
        }
        for(int i=1;i<=n;++i)
            cout<<(distan[i]>=(ll)(2e18)?-1:distan[i])<<' ';
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