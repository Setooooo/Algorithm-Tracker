//
// Created by beHe on 2026/10/24.
//
//  https://ac.nowcoder.com/acm/contest/141878/D

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

using ll=long long;
constexpr ll INF = numeric_limits<ll>::max();
constexpr ll MAXN = 5e5;

struct Node {
  ll val;
}Seg[MAXN<<2];

void build(int index,int L,int R,vector<ll>&arr) {
  if (L==R) {
    if (arr[L]==INF) Seg[index].val = INF;
    else {
      Seg[index].val = arr[L];
    }
  }
  else {
    int mid = (L+R)/2;
    int cl = index<<1;
    int cr = index*2+1;
    build(cl,L,mid,arr);
    build(cr,mid+1,R,arr);
    Seg[index].val = max(Seg[cr].val,Seg[cl].val);
  }
}

void update(int index,int L,int R,ll val,int i) {
  if (L==R) {
    Seg[index].val = val;
  }else {
    int mid = (L+R)/2;
    int cl = index*2;
    int cr = index*2+1;
    if (i<=mid) update(cl,L,mid,val,i);
    if (i>mid) update(cr,mid+1,R,val,i);
    Seg[index].val = max(Seg[cr].val,Seg[cl].val);
  }
}

ll query(int index,int L,int R,int l,int r) {
  if (l<=L&&R<=r) {
    return Seg[index].val;
  }else {
    int mid = (L+R)/2;
    int cl = index*2;
    int cr = index*2+1;
    ll result = -INF;
    if (l<=mid) result = max(result,query(cl,L,mid,l,r));
    if (r>mid) result = max(result,query(cr,mid+1,R,l,r));
    return result;
  }
}

// 线段树的代码

void solve() {
  int n,m,k;
  cin >> n >> m >> k;

  vector<int> attackPositions(k+1);
  int attackPosition;
  vector<ll>first(n+1,INF);
  vector<ll>next(k+1,INF);

  for (int i= 1;i<=k;++i) {
    cin>>attackPosition;
    attackPositions[i]=attackPosition;
  }
  for (int i=k;i>=1;--i) {
    next[i]=first[attackPositions[i]];
    first[attackPositions[i]]=i;
  }
  // 根据这个数组建树,最大线段树，只按照每个元素的第一个元素，如果没有元素那么设置为无穷
  build(1,1,n,first);

  // 开始统计第一次攻击发生的情况，我们使用一个m长度的窗口扫描每一个人他是否可以被攻击，可以被攻击则是有第一次攻击时间，否则是无穷的时刻
  // 同时我们开始建立events数组 下标表示当前的位置是否被攻击，在上面扫描的过程中如果发现设置为一
  vector<vector<int>>events(k+1);
  ll t;
  vector<int>ans(n+1,0);
  for (int i=m;i<=n;++i) {
    t= query(1,1,n,i-m+1,i);
    if (t<=k)
      events[t].emplace_back(i);
  }

  // 每次我们更新一个时刻
  for (int i=1;i<=k;++i) {
    update(1,1,n,next[i],attackPositions[i]);
    for (auto j:events[i]) {
      ans[j]++;
      ll T = query(1,1,n,j-m+1,j);
      if (T<=k) events[T].emplace_back(j);
    }
  }

  for (int i=1;i<=n;++i) {
    cout<<ans[i]<<" ";
  }

}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
