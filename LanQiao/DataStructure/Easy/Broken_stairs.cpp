//
// Created by 19233 on 2025/2/20.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

const int N=1e5+10;
bool is_broke[N];
ll dp[N],mod=1e9+7;

void solve()
{
    int n,m,pos;
    cin>>n>>m;
    for (int i=0;i<m;++i) {
        cin>>pos;is_broke[pos+1]=true;
    }
    dp[1]=1;
    for (int i=2;i<=n+1;++i) {
        if (is_broke[i])continue;
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    cout<<dp[n+1];
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