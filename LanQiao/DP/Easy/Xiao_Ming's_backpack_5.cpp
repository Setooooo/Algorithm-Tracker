//
// Created by beHe on 25-2-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,v;
    cin>>n>>v;
    vector<vector<int>>dp(n+1,vector<int>(v+1,0));
    int s,w,val;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=v;++j)
            dp[i][j]=dp[i-1][j];
        cin>>s;
        while (s--){
            cin>>w>>val;
            for(int j=w;j<=v;++j)
                dp[i][j]=max(dp[i][j],dp[i-1][j-w]+val);
        }
    }
    cout<<dp[n][v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    while (T--)
    {
        solve();
    }
}