//
// Created by beHe on 25-3-17.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//走多远
using namespace std;

using ll=long long;
using ull=unsigned long long;

class So{
    int n,m;
    vector<vector<int>>graph;
    vector<int>dp,rudu;
public:
    So(int n_,int m_):n(n_),m(m_),graph(n+1),dp(n+1,0),rudu(n+1,0){
        int x,y;
        for(int i=0;i<m;++i)
            cin>>x>>y,graph[x].emplace_back(y),++rudu[y];
        queue<int>dui;
        for(int i=1;i<=n;++i)
            if(rudu[i]==0) dui.emplace(i);
        while (!dui.empty()){
            int now=dui.front(); dui.pop();
            for(auto i:graph[now]){
                dp[i]=max(dp[now]+1,dp[i]),--rudu[i];
                if(rudu[i]==0) dui.emplace(i);
            }
        }
        cout<<*max_element(dp.begin()+1,dp.end());
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    So nso(n,m);
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