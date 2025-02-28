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
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<endl;
    //如何求这个最长公共子序列
    int i=n,j=m;
    vector<int> ans;
    while (i>=1&&j>=1) {
        if (dp[i][j]==dp[i-1][j-1]+1) {
            ans.emplace_back(a[i]);--i,--j;
        }else {
            if (dp[i-1][j]>=dp[i][j-1])
                --i;
            else --j;
        }
    }
    reverse(ans.begin(),ans.end());
    for (const auto& x : ans)
        cout<<x<<" ";
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