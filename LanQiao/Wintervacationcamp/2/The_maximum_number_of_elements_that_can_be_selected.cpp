//
// Created by beHe on 25-4-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//能选取元素的最多个数
using namespace std;

using ll=long long;
using ull=unsigned long long;



void solve()
{
    int n,x;
    cin>>n;
    map<int,int>vis;
    for(int i=0;i<n;++i)
    {
        cin>>x;if(vis[x]<2) ++vis[x];
    }
    int ans=0;
    for(const auto &[key,val]:vis)
        ans+=val;
    if((prev(vis.end()))->second==2) --ans;
    cout<<ans;
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