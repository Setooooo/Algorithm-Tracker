//
// Created by beHe on 25-4-5.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,m;
    vector<vector<int>>graph;
    vector<pair<int,int>>ver;
    vector<int>col;
public:
    Solution(int n_,int m_):n(n_),m(m_),graph(n+1),ver(m),col(n+1,-1){
        bool flage=true;
        for(int i=0;i<m;++i){
            cin>>ver[i].first>>ver[i].second;
            graph[ver[i].first].emplace_back(ver[i].second),
                    graph[ver[i].second].emplace_back(ver[i].first);
        }
        for(int i=1;i<=n;++i)
            if(col[i]==-1)
                if(!dfs(i,1)){
            flage=false;
            return;
                }
        if(flage) puts("Yes");
        else puts("No");
    };
    bool dfs(int u, int color) {
        col[u] = color;

        for(const auto i:graph[u]){
            if(col[i]==-1) {
                if(!dfs(i,col[u]^1)) return false;
            }
            else if(col[i]==col[u]) return false;
        }
        return true;
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