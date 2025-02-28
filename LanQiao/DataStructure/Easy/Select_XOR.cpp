//
// Created by beHe on 25-2-26.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll mod=998244353;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<ll>dp(64,0),dp2(64,0);
    vector<int>arr(n+1);
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    dp[0]=1;
     for(int i=1;i<=n;++i){
        for(int j=0;j<64;++j){
            dp2[j^arr[i]]=(dp[j^arr[i]]+dp[j])%mod;
        }
        swap(dp,dp2);
    }
    cout<<dp[x]<<'\n';
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