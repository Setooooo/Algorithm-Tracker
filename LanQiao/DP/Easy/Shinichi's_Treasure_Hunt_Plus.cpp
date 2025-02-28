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
    int n,bag;
    cin >> n >> bag;
    vector<ull>dp(bag + 1, 0);
    int spli[20],p,w,v,s,lo;
    for(int i=0;i<n;++i)
    {
        cin>>w>>v>>s;
        for(int k=1;k<=s;s-=k,k+=k)
        {
            for(ll j=bag;j>=w*k;--j)
                dp[j]=max(dp[j],dp[j-w*k]+v*k);
        }
        if(s)
            for(ll j=bag;j>=w*s;--j)
                dp[j]=max(dp[j],dp[j-s*w]+v*s);
    }
    cout<<dp[bag];
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