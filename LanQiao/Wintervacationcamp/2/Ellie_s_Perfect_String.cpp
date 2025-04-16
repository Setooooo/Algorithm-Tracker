//
// Created by beHe on 25-4-9.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//爱丽的完美的串
using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
  int k,d,siz;string str;
  cin>>k>>d>>str;
  vector<vector<vector<ll>>>dp(2,vector<vector<ll>>(k+1,vector<ll>(d+1,-2e10)));
  siz=str.size(); int now=0,pre=1;
  dp[pre][0][0]=0;
  for(int x=0;x<siz;++x){
    for(int i=0;i<=k;++i) fill(dp[now][i].begin(),dp[now][i].end(),-2e10);
    if(str[x]=='1'){
      for(int i=0;i<=k;++i) {
        for(int j=1;j<=d-1;++j)
          dp[now][i][j]=dp[pre][i][j-1];
        dp[now][i][0]=dp[pre][i][d-1]+1;
      }
    }else{
      for(int i=0;i<=k;++i) {
        for(int j=0;j<=d-1;++j) {
          dp[now][i][0]=max(dp[pre][i][j],dp[now][i][0]);
        }
      }
      for(int i=1;i<=k;++i){
        for(int j=1;j<=d-1;++j) dp[now][i][j]=max(dp[pre][i-1][j-1],dp[now][i][j]);
        dp[now][i][0]=max(dp[pre][i-1][d-1]+1,dp[now][i][0]);
      }
    }
    now^=1,pre^=1;
  }
  ll ans=0;
  for(int i=0;i<=k;++i) //这里使用k个魔法棒的最大答案也可以通过测试
    for(int j=0;j<d;++j)
      ans=max(ans,dp[pre][i][j]);
  cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}