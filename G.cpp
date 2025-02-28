//
// Created by 19233 on 2025/1/26.
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

const int N=1e5+10;
int n,k,add,red;
struct ball{
    int pos,v;
};
ball arr[N];
int pob[N],net[N];

ll cnt(ll mid)
{
  ll res=0;
  for(int i=0;i<add;++i)
  {
    int *p1=upper_bound(net,net+red,pob[i]+mid);
    int *p2=upper_bound(net,net+red,pob[i]);
    res+=p1-p2;
  }
  return res;
}

void solve()
{
  cin>>n>>k;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i].pos>>arr[i].v;
    if(arr[i].v==1)
      pob[add++]=arr[i].pos;
    else
      net[red++]=arr[i].pos;
  }
  int maxk=0;
  sort(pob,pob+add),sort(net,net+red);
  for(int i=0;i<red;++i)
  {
    maxk+= lower_bound(pob,pob+add,net[i])-pob;
  }
  if(maxk<k)
  {
    cout<<"No";
    return;
  }
  ll l=0,r=1e9,mid;
  while (l<r)
  {
    mid=(l+r)>>1;
    if(cnt(mid)>=k)
    {
      r=mid;
    }
    else
    {
      l=mid+1;
    }
  }
    cout<<"Yes\n";
    cout<<fixed<<setprecision(6)<<1.0*l/2;
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