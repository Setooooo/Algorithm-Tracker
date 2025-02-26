//
// Created by 19233 on 2025/2/5.
//
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;
using ll=long long;
using ull=unsigned long long;

class UnionbyRank
{
    //n代表元素个数
    int n;
    vector<int>father,height;
public:
    UnionbyRank(int _n);
    int getfather(int);
    void merge(int,int);
};

UnionbyRank::UnionbyRank(int _n)
  :n(_n),father(_n+1),height(_n+1,0)
{
    for(int i=0;i<=n;++i)
      father[i]=i;
}

int UnionbyRank::getfather(int x) {
  while (x!=father[x])x=father[x];
  return father[x];
}

void UnionbyRank::merge(int x, int y) {
  int fx= getfather(x),fy= getfather(y);
  if(height[fx]>height[fy])swap(fx,fy);
  father[fx]=fy;
  if(height[fx]==height[fy])++height[fy];
}


void solve()
{

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