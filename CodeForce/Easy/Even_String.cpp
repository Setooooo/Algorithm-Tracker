//
// Created by Seto on 2025-04-15
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr ll maxn=5e5+10,p=998244353;
vector<ll>pos(maxn,1),invpos(maxn,1);

ll qpow(ll a,ll b) {
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%p; a=a*a%p,b>>=1;
  }
  return res;
}

void solve()
{
  vector<int>latin(26,0);
  for(auto &i:latin) cin>>i;
  ll s=accumulate(latin.begin(), latin.end(),0LL);
  vector<ll>dp(s+1,0); dp[0]=1;
  for(const auto i:latin){
    if(i==0) continue;
    for(int j=s;j-i>=0;--j){
      dp[j]=(dp[j]+dp[j-i])%p;
    }
  }
  ll ans=pos[(s+1)/2]*pos[s/2]%p*dp[s/2]%p;
  for(auto i:latin){
    if(i==0) continue;
    ans=(ans*invpos[i])%p;
  }
  cout<<ans<<'\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr),cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());
//计算阶乘和它的逆元
  {
    for(int i=1;i<maxn;++i) pos[i]=pos[i-1]*i%p;
    invpos[maxn-1]=qpow(pos[maxn-1],p-2);
    for(int i=maxn-2;i>=0;--i) invpos[i]= invpos[i+1]*(i+1)%p;
  }

  int T=1;
    cin>>T;
  while (T--)
  {
    solve();
  }
}