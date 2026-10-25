//
// Created by Seto on 2025-04-16
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr ll maxn=19,p=2520;
ll idx[maxn];
ll dp[maxn][p+1][50];
ll a[maxn],len;
int book[p+1];


ll dfs(int pos,bool limit,ll prelcm,ll mo) {
  if(pos==0) return mo%prelcm==0;
  if(!limit&&dp[pos][mo][book[prelcm]]!=-1) return dp[pos][mo][book[prelcm]];
  int up=limit?a[pos]:9;
  ll ans=0;
  for(int i=0;i<=up;++i){
    if(i==0) ans+= dfs(pos-1,limit&&i==up,prelcm,mo*10%p);
    else ans+=dfs(pos-1,limit&&i==up,lcm(prelcm,i),(mo*10%p+i)%p);
  }
  if(!limit) dp[pos][mo][book[prelcm]]=ans;
  return ans;
}

ll cnt(ll n){
  ll res=n; len=0;
  while(res) a[++len]=res%10,res/=10;
  return dfs(len,true,1,0);
}

void solve() {
  ll x,y; cin>>x>>y;
  cout<<cnt(y)-cnt(x-1)<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());
  memset(dp, -1, sizeof(dp));
  {
    int j=0;
    for(int i=1;i<=p;++i){
        if(p%i==0) book[i]=++j;
    }
  }

  int T = 1;
    cin>>T;
  while (T--) {
    solve();
  }
}