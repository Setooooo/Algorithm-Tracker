//
// Created by beHe on 25-2-27.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>w(n+1),v(n+1);
    vector<array<ll,2>>dp(m+1,array<ll,2>());
    for(int i=1;i<=n;++i)
        cin>>w[i]>>v[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=w[i];--j){
                dp[j][0]=max(dp[j][0],dp[j-w[i]][0]+v[i]),dp[j][1]=max(dp[j][1],dp[j-w[i]][1]+v[i]);
            if(j>=w[i]+k)
                dp[j][1]=max(dp[j][1],dp[j-w[i]-k][0]+2*v[i]);

        }
    }
    cout<<max(dp[m][0],dp[m][1]);
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