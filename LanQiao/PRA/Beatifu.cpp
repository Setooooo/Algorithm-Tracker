//
// Created by Seto on 2025-05-15
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
ll maxn=10000;

void solve() {
    ll k;
    cin>>k;
    vector<ll>pos;
    pos.emplace_back(1);
    for(ll i=1+k,now=1,ed=1;i<=maxn;++i){
      if(gcd(i,now)==1){
        pos.emplace_back(i);
        now=i+1;
        i+=k;
      }
    }
    int t,x; cin>>t;
    while(t--){
      cin>>x;
      auto it = lower_bound(pos.begin(),pos.end(),x);
      ll dis=it-pos.begin();
      cout<<dis<<'\n';
    }
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