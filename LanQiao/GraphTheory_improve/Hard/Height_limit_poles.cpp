//
// Created by beHe on 25-3-29.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//限高杆
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m;
    struct neber{
        int v;
        bool limit;
        ll weight;
    };
    struct node{
        int no,use_limit;
        ll disno;
        bool operator<(const node&ri) const {return disno>ri.disno;}
    };
    vector<vector<neber>>graph;
    vector<ll>dist;
public:
    Solution(int n_,int m_):n(n_),m(m_),
    dist(n+1,2e18),graph(n+1){
        int a,b,c,d;
        vector<pair<int,int>>li;
        for(int i=0;i<m;++i){
            cin>>a>>b>>c>>d,
                graph[a].push_back({b,(bool)d,c}),
                graph[b].push_back({a,(bool)d,c});
            if(d==1) li.push_back({a,graph[a].size()-1}),li.push_back({b,graph[b].size()-1});
        }
    };
    void dijkstra(int start){
        fill(dist.begin(),dist.end(),2e18);
        priority_queue<node>pq;
    }
};


void solve()
{

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