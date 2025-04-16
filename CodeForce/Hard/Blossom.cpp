//
// Created by beHe on 25-4-13.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll p=1e9+7;


struct Combine{
    static int N;
    vector<ll>pos,nev;
public:
    Combine():pos(N),nev(N){
      pos[0]=1;
      for(int i=1;i<N;++i) pos[i]=(pos[i-1]*i)%p;
      nev[N-1]=qpow(pos[N-1],p-2);
      for(int i=N-2;i>=0;--i) nev[i]=nev[i+1]*(i+1)%p;
    }
    static ll qpow(ll x,ll mi){
      ll res=1;
      while(mi){
        if(mi&1) res=(res*x)%p;
        mi>>=1,x=x*x%p;
      }
      return res;
    }
    ll combine(ll a,ll b) const{
      if (a < 0 || b < 0 || a < b)
        return 0;
      return pos[a]*nev[a-b]%p*nev[b]%p;
    }
};
int Combine::N=2e5+10;
Combine com;

constexpr int N=5005;
vector<int>arr(N),fix_no(N,0);
vector<bool>vis(N,false);
vector<vector<int>> dp(N,vector<int>(N,0));

void solve()
{
  int n,cnt_neg=0;
  cin>>n;
  //初始化
  {
    fill(arr.begin(), arr.begin()+n+1,0);
    fill(fix_no.begin(), fix_no.begin()+n+1,0);
    std::fill(vis.begin(), vis.begin()+n+1,false);
    for(int i=0;i<=n;++i) fill(dp[i].begin(), dp[i].end(),0);
  }
  for(int i=1;i<=n;++i){
    cin>>arr[i];
    if(arr[i]==-1) ++cnt_neg;
    else vis[arr[i]]=true;
    fix_no[i]=cnt_neg;
  }
  int mmex=n;
  for(int i=1;i<=n;++i){
    int rimex=mmex;
    for(int j=n;j>=i;--j){
      int ne=fix_no[j]-fix_no[i-1];
      dp[ne][0]++,dp[ne][rimex]--;
      if(arr[j]!=-1) rimex=min(arr[j],rimex);
    }
    if(arr[i]!=-1) mmex=min(mmex,arr[i]);
  }
  for(int i=0;i<=fix_no[n];++i){
    for(int j=1;j<=n;++j)
      dp[i][j]+=dp[i][j-1];
  }
  int ans=0,cnt=0;
  for(int i=0;i<n;++i){
    cnt+=(!vis[i]);
    for(int j=cnt;j<=fix_no[n];++j)
      ans = (ans + 1LL * com.combine(j,cnt) * com.pos[cnt]%p*com.pos[fix_no[n]-cnt]%p*dp[j][i])%p;
  }
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