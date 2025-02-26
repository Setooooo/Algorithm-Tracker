//
// Created by 19233 on 2025/2/20.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=1e6+10;
constexpr ll mod=1e9+7;
ll dp[N][2];

/**
 * 感觉dp好像也没那么难，但是如果我写的话，我想我得多注意
 */
void solve()
{
    int n,k;
    cin>>n>>k;
    dp[1][0]=dp[1][1]=1;
    for (int i=2;i<=k+1;++i) {
        dp[i][0]=1;dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
    }
    for (int i=k+2;i<=n;++i) {
        dp[i][1]=(dp[i-k-1][0]+dp[i-k-1][1])%mod;
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
    }
    cout<<(dp[n][1]+dp[n][0])%mod;
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