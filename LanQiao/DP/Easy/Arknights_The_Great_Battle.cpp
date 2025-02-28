//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,m,v;
    cin>>n>>m>>v;
    vector<ull>dp(v+1,0);
    vector<pair<int,int>>arr(n);
    for(auto &i:arr)
        cin>>i.first>>i.second;
    int maxn=0,x;
    for(int i=0;i<m;++i){
        cin>>x;
        maxn=max(x,maxn);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=v;j>=arr[i].second;--j)
            dp[j]=max(dp[j],dp[j-arr[i].second]+arr[i].first);
    }
    if(dp[v])
        cout<<(maxn+dp[v]-1)/dp[v];
    else
        cout<<-1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    ifstream file("");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}