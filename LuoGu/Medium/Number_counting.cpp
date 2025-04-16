//
// Created by Seto on 2025-04-16
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int maxn=15;
ll a[maxn],b[maxn],digital[maxn];
ll mi[maxn],dp[maxn];

void cnt(ll res,ll *arr){
  ll tmp=res,len=0;
  while(res){
    digital[++len]=res%10,res=res/10;
  }
  for(int i=len;i>=1;--i){
    for(int d=0;d<10;++d) arr[d]+=dp[i-1]* digital[i];
    for(int j=0;j<digital[i];++j) arr[j]+=mi[i-1];
    tmp-=mi[i-1]*digital[i];
    arr[digital[i]]+=tmp+1;
    arr[0]-=mi[i-1];
  }
}

void solve()
{
  mi[0]=1;
  for(int i=1;i<maxn;++i)
    dp[i]=dp[i-1]*10+mi[i-1],mi[i]=mi[i-1]*10;
  ll x,y; cin>>x>>y;
  cnt(y,a),cnt(x-1,b);
  for(int i=0;i<10;++i)
    cout<<a[i]-b[i]<<' ';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T = 1;
//    cin>>T;
  while (T--) {
    solve();
  }
}