//
// Created by 19233 on 2025/2/6.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

const int N=2e5+10;
struct node{
    int sl,sr,val;
}Seg[N*40];

int n,k,m,rbound;
int arr[N];
vector<int>soarr;
unordered_map<int,int>func;

void read()
{
  cin>>n>>m;
  soarr.reserve(n);
  for(int i=1;i<=n;++i)
    cin>>arr[i],soarr.emplace_back(arr[i]);
  sort(soarr.begin(), soarr.end());
  soarr.resize(unique(soarr.begin(), soarr.end())-soarr.begin());
  {
    unsigned int len=soarr.size();
    for(int i=0;i<len;++i)
      func.emplace(soarr[i],i+1);
    for(int i=1;i<=n;++i)
      arr[i]=func[arr[i]];
    rbound=len+1;
  }
}
int o,version[N];
void update(int &no,int old,int l,int r,int pos)
{
  no=++o;
  Seg[no]=Seg[old];
  if(l==r)
  {
    ++Seg[no].val;
    return;
  }
  int mid=(l+r)>>1;
  if(mid < pos)update(Seg[no].sr, Seg[old].sr, mid + 1, r, pos);
  else update(Seg[no].sl, Seg[old].sl, l, mid, pos);
  Seg[no].val=Seg[Seg[no].sl].val+Seg[Seg[no].sr].val;
}

ll query(int ol, int no, int l, int r, int L, int R)
{
  if(L<=l&&r<=R)
  {
    return Seg[no].val-Seg[ol].val;
  }
  int mid=(l+r)>>1; ll res=0;
  if(mid<R) res+=query(Seg[ol].sr,Seg[no].sr,mid+1,r,L,R);
  if(mid>=L) res+=query(Seg[ol].sl,Seg[no].sl,l,mid,L,R);
  return res;
}

void solve()
{
  read();
  //已经读入 m
  int l,r;
  ll Rev_Pair=0;
  Seg[0].sl=Seg[0].sr=Seg[0].val=0;
  for(int i=1;i<=n;++i)
  {
    Rev_Pair+= query(version[0],version[i-1],0,rbound,arr[i]+1,rbound);
    update(version[i],version[i-1],0,rbound,arr[i]);
  }
  while (m--)
  {
    cin>>l>>r;
    ll res=0;
    // think 1
    if(arr[l]>arr[r]) --res;
    else if(arr[l]<arr[r]) ++res;
    res-= query(version[l],version[r-1],0,rbound,arr[r]+1,rbound);
    res+= query(version[l],version[r-1],0,rbound,0,arr[r]-1);
    res-= query(version[l],version[r-1],0,rbound,0,arr[l]-1);
    res+= query(version[l],version[r-1],0,rbound,arr[l]+1,rbound);
    cout<<res+Rev_Pair<<'\n';
  }
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