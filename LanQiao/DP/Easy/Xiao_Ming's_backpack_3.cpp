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
    cin>>n>>bag;
    vector<int>dp(bag+1,0);
    int w,v,s;
    for(int i=0;i<n;++i)
    {
        cin>>w>>v>>s;
        for (int k=s;k;--k){
            // 0 1 背包倒着更新
            for(int j=bag;j>=w;++j)
                dp[j]=max(dp[j],dp[j-w]+v);
        }
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