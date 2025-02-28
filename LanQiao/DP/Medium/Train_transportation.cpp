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
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    int w;
    for(int i=0;i<n;++i){
        cin>>w;
        for(int j=a;j>=0;--j)
            for(int k=b;k>=0;--k)
            {
                if(j>=w)dp[j][k]=max(dp[j][k],dp[j-w][k]+w);
                if(k>=w)dp[j][k]=max(dp[j][k],dp[j][k-w]+w);
            }
    }
    cout<<dp[a][b];
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