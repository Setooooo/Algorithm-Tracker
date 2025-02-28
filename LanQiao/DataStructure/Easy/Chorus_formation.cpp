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
    vector<int> v(n+1),dp(n+1,1),dp2(n+1,1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j=i-1;j>=1;j--) {
            if (v[j]<v[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for (int i = n; i>=1;i--) {
        for (int j=i+1;j<=n;j++) {
            if (v[j]<v[i]) dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
    int ans=1000;
    for (int i = 1; i <= n; i++) {
        ans=min(ans,n-(dp[i]+dp2[i]-1));
    }
    cout<<ans;
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