//
// Created by 19233 on 2025/2/6.
//
#include <bits/stdc++.h>
using namespace std;

struct RollbackUnionFind {
    vector<int> parent, sz;
    stack<pair<int,int>> history; // 记录 (x 的父亲之前的值)

    RollbackUnionFind(int n){
      parent.resize(n+1);
      sz.resize(n+1, 1);
      for(int i=1;i<=n;i++){
        parent[i] = i;
      }
    }

    int findp(int x){
      while(parent[x]!=x) x=parent[x];
      return x;
    }

    bool unite(int a,int b){
      a=findp(a); b=findp(b);
      if(a==b){
        history.push({-1,-1});
        return false;
      }
      if(sz[a]<sz[b]) swap(a,b);
      history.push({b,parent[b]});
      parent[b]=a;
      sz[a]+=sz[b];
      return true;
    }

    void rollback(){
      auto &bk=history.top();
      history.pop();
      if(bk.first==-1) return;
      int b=bk.first;
      int oldp=bk.second;
      int a=parent[b];
      parent[b]=oldp;
      sz[a]-=sz[b];
    }
};

// 全局或静态存储，保证性能
static const int MAXM = 200000*4+5; // 4*M 大小的线段树

// 每个节点存储在该时间段内一直存在的边列表
vector<pair<int,int>> seg[MAXM];

// 将区间 [l,r) 插入线段树，表示边在这个区间内一直存在
void addEdge(int idx,int start,int end,int l,int r,pair<int,int> edge){
  if(l>=r) return;
  if(l<=start && end<=r){
    seg[idx].push_back(edge);
    return;
  }
  int mid=(start+end)>>1;
  if(l<mid) addEdge(idx<<1, start, mid, l, r, edge);
  if(r>mid) addEdge(idx<<1|1, mid, end, l, r, edge);
}

// 存放每个查询的答案
// ans[i] = 'Y' or 'N'
vector<char> ans;

// DFS 线段树 + 回滚并查集
// 区间 [start, end) 覆盖的查询就是操作编号在 [start, end) 范围的
// qOps: 把每个操作存起来，以便在对应段查询
void solveSeg(int idx,int start,int end, RollbackUnionFind &uf,
              const vector<array<int,3>> &qOps){
  // 先把当前节点所有边 unite
  int before = 0;
  // 记录一下添加了多少次 union，好在回滚时一次性撤销
  // 或者也可以每次 unite 返回 bool，自行累计
  for(auto &e : seg[idx]){
    uf.unite(e.first, e.second);
    before++;
  }

  if(end - start == 1){
    // 叶子节点，对应唯一的操作编号 == start
    // 如果是查询操作，就当场判断
    int i = start;  // 操作下标
    if(qOps[i][0]==2){
      int u=qOps[i][1], v=qOps[i][2];
      ans[i]=(uf.findp(u)==uf.findp(v))?'Y':'N';
    }
  } else {
    int mid=(start+end)>>1;
    solveSeg(idx<<1, start, mid, uf, qOps);
    solveSeg(idx<<1|1, mid, end, uf, qOps);
  }

  // 回滚
  while(before--){
    uf.rollback();
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N,M;
  cin >> N >> M;

  // 记录所有操作
  // qOps[i] = {type, u, v}
  // type = 1 or 2
  // u,v 为节点编号
  vector<array<int,3>> qOps(M+1);
  for(int i=1;i<=M;i++){
    cin >> qOps[i][0] >> qOps[i][1] >> qOps[i][2];
  }

  // 用 map<(u,v), int> 记录当前边 (u,v) 是从什么时候开始存在的
  // 注意存储时，保证 (u,v) 中 u < v 避免重复
  map<pair<int,int>, int> edgeMap;

  // 对每条操作，确定边的存在区间
  for(int i=1;i<=M;i++){
    int t=qOps[i][0], u=qOps[i][1], v=qOps[i][2];
    if(u>v) swap(u,v); // 保持有序

    if(t==1){
      // 切换边 (u,v)
      auto it = edgeMap.find({u,v});
      if(it == edgeMap.end()){
        // 之前不存在 -> 现在开始存在
        edgeMap[{u,v}] = i;
      } else {
        // 之前已存在 -> 现在到 i 为止
        int startTime = it->second;
        // 区间 [startTime, i)
        addEdge(1,1,M+1, startTime, i, {u,v});
        // 删掉这条边的记录
        edgeMap.erase(it);
      }
    }
    // t=2（查询）不影响边的开关
  }

  // 所有操作处理完后，若还有在 edgeMap 里的边，说明它们仍然存在
  for(auto &kv : edgeMap){
    int startTime = kv.second;
    auto &uv = kv.first;
    // 活跃区间 [startTime, M+1)
    addEdge(1, 1, M+1, startTime, M+1, uv);
  }

  ans.resize(M+1, ' ');

  RollbackUnionFind uf(N);

  // 在线段树上做 DFS
  solveSeg(1,1,M+1,uf, qOps);

  // 输出答案
  // 只有 type=2 的操作需要输出
  for(int i=1;i<=M;i++){
    if(qOps[i][0]==2){
      cout << ans[i] << "\n";
    }
  }

  return 0;
}
