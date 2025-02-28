//
// Created by beHe on 25-2-26.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n+1),dp(n+1,1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for (int i=1;i<=n;i++)
        for (int j=i-1;j>0;--j)
            if (v[j]<v[i])
                dp[i]=max(dp[i],dp[j]+1);
    cout<<dp[n]<<'\n';
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