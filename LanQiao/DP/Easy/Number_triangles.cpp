//
// Created by beHe on 25-2-27.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

const int N=110;

ll arr[N][N],dp[N][N][N];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=i;++j)
            cin>>arr[i][j];
    for (int i=n;i>0;--i)
        for (int j=1;j<=i;++j)
            for (int k=0;k<=n-i;++k) {
                if (k>=1)
                    dp[i][j][k]=max(dp[i+1][j][k],dp[i+1][j+1][k-1])+arr[i][j];
                else
                    dp[i][j][k]=dp[i+1][j][k]+arr[i][j];
            }
    if (n&1)
        cout<<dp[1][1][n/2]<<'\n';
    else
        cout<<max(dp[1][1][(n-1)/2],dp[1][1][n-1-(n-1)/2])<<'\n';
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