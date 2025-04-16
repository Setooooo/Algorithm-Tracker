//
// Created by beHe on 25-3-20.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m,h;
    vector<vector<pair<int,ll>>>graph;
    bitset<200010>house;
    vector<pair<ll,ll>>mar,rob;
    struct Node{
        int p;bool house;
        ll dis;
    };
    struct cmp{
        bool operator()(const Node&left,const Node&right){
            return left.dis>right.dis;
        }
    };

public:
    Solution(int n_,int m_,int h_):n(n_),m(m_),h(h_),graph(n+1),house(false),mar(n+1,{2e18,2e18}),rob(n+1,{2e18,2e18}){
        int u,v,w;
        for(int i=0;i<h;++i)
            cin>>w,house[w]=true;
        for(int i=0;i<m;++i)
            cin>>u>>v>>w,graph[u].emplace_back(v,w),graph[v].emplace_back(u,w);
        djstra2(mar,1), djstra2(rob,n);
        ll ans=2e18,x,y;
        for(int i=1;i<=n;++i)
        {
            x=min(mar[i].first,mar[i].second);
            y=min(rob[i].first,rob[i].second);
            ans=min(ans, max(x,y) );
        }
        cout<<(ans!=(ll)(2e18)?ans:-1)<<'\n';
    }
    void djstra(vector<pair<ll,ll>>&col,int point){
        priority_queue<Node,vector<Node>,cmp>pq;
        if(house[point])
            pq.emplace(point,true,0);
        else
            pq.emplace(point,false,0);
        while (!pq.empty()){
            auto [no,hos,wi]=pq.top(); pq.pop();
            if(hos){
                if(wi>=col[no].second) continue;
                col[no].second=wi;
            }else{
                if(wi>=col[no].first) continue;
                col[no].first=wi;
            }
            for(const auto &i:graph[no]){
                if(hos) pq.emplace(i.first,1,wi+i.second/2);
                else if(house[i.first]) pq.emplace(i.first,1,wi+i.second);
                else pq.emplace(i.first,0,wi+i.second);
            }
        }
    }
     void djstra2(vector<pair<ll,ll>>&col,int point){
        priority_queue<Node,vector<Node>,cmp>pq;
         col[point].first = house[point] ? 2e18 : 0;  // 修正初始状态
         col[point].second = house[point] ? 0 : 2e18;
        if(house[point]) pq.emplace(point,1,0);
        else pq.emplace(point,0,0);
        while(!pq.empty()){
            auto [p,ho,dis]=pq.top(); pq.pop();
            if(ho && dis > col[p].second) continue;  // 骑马状态检查
            if(!ho && dis > col[p].first) continue;  // 步行状态检查

            for(const auto &[next,wei]:graph[p]){
                if(ho){
                    if(dis+wei/2<col[next].second)
                        pq.emplace(next,1,col[next].second=dis+wei/2);
                }else{
                    if(dis+wei<col[next].first)
                        pq.emplace(next, house[next], col[next].first= dis + wei);
                }
            }
        }
    }
};


void solve()
{
    int n,m,h;
    cin>>n>>m>>h;
    Solution one(n,m,h);
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