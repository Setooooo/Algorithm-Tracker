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
    int n,v;
  cin>>n>>v;
  vector<int>weight(n+1),val(n+1),dp(v+1,0);
  for (int i=1;i<=n;i++)
    cin>>weight[i]>>val[i];
  for (int i=1;i<=n;i++)
    for (int j=v;j>=weight[i];--j)
      dp[j]=max(dp[j],dp[j-weight[i]]+val[i]);
  cout<<dp[v]<<endl;
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