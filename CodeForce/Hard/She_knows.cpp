//
// Created by Seto on 2025-04-20
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;
constexpr ll p=1e9+7;
ll qpow(ll a,ll b){
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%p;a=a*a%p,b>>=1;
  }
  return res;
}

void solve() {
  ll n,m,k,x,y,col;
  cin>>n>>m>>k;
  ll good=0,ed=0;
  for(int i=0;i<k;++i){
    cin>>x>>y>>col;
    if(((x==1||x==n)&&(y>1&&y<m))||((y==1||y==m)&&(x>1&&x<n))){
      good=col?good+1:good; ++ed;
    }
  }
  if(ed==(m+n-4)*2){
    if(1&good) cout<<"0\n";
    else cout<<qpow(2,m*n-k)<<'\n';
  }else
    cout<<qpow(2,m*n-k-1)<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T = 1;
    cin>>T;
  while (T--) {
    solve();
  }
}