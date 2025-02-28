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
    int n,v;
    cin>>n>>v;
    vector<ull>dp(v+1,0);
    int val,w,m;
    for(int i=0;i<n;++i)
    {
        cin>>val>>w>>m;
        for(int k=1;k<=m;m-=k,k+=k)
            for(int j=v;j>=k*w;--j)
                dp[j]=max(dp[j],dp[j-w*k]+k*val);
        if(m)
            for(int j=v;j>=m*w;--j)
                dp[j]=max(dp[j],dp[j-m*w]+m*val);
    }
    cout<<dp[v];
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