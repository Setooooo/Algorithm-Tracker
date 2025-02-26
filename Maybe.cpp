//
// Created by 19233 on 2024/12/20.
//
//
#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

const int N =1e6+6,INF = 0x3f3f3f3f;
int n,m,ans[N],maxy=-INF,c[N];

struct P{
    int t,x,y;
}a[N],b[N];

bool operator<(const P pre, const P las){
    return pre.x < las.x || (pre.x == las.x && pre.y < las.y);
}

void add(int pos,int num)
{
    while (pos<maxy)
    {
        c[pos]=max(num,c[pos]);
        pos+=pos&-pos;
    }
}

int ask(int pos)
{
    int res=-INF;
    while (pos){
        res=max(c[pos],res);
        pos-=pos&-pos;
    }
    return res;
}

void re(int pos){
    while (pos<maxy){
        c[pos]=-INF;
        pos+=pos&-pos;
    }
}

void work(int ba,int ed,int w,int dx,int dy)
{
    for(int i=ba;i != ed;i+=w)
    {
        int y=dy==1?b[i].y:maxy-b[i].y;
        int num=dx*b[i].x+dy*b[i].y;
        if(a[b[i].t].t==1)
            add(y,num);
        else
            ans[b[i].t]=min(ans[b[i].t],num-ask(y));
    }
    for(int i=ba;i!=ed;i+=w)
        if(a[b[i].t].t==1)
            re(dy==1?b[i].y:maxy-b[i].y);
}

void CDQ(int l,int r)
{
    int mid=(l+r)>>1;
    if (l < mid) CDQ(l, mid);
    if (mid + 1 < r) CDQ(mid + 1, r);
    int tot=0;
    for(int i=l;i<=r;++i)
    {
        if((i<=mid&&a[i].t==1)||(i>mid&&a[i].t==2))
        {
            b[++tot]=a[i];
            b[tot].t=i;
        }
    }
    sort(b+1,b+1+tot);
    work(1,tot+1,1,1,1);
    work(1,tot+1,1,1,-1);
    work(tot,0,-1,-1,-1);
    work(tot,0,-1,-1,1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i!=n+1;++i)
    {
        cin>>a[i].x>>a[i].y;
        a[i].x++;
        a[i].t=1;
        maxy=max(maxy,a[i].y);
    }
    for(int i=n+1;i!=n+m+1;++i)
    {
        cin>>a[i].t>>a[i].x>>a[i].y;
        a[i].x++;
        maxy=max(maxy,a[i].y);
    }
    ++maxy;
    memset(ans, 0x3f, sizeof(ans));
    memset(c, 0xcf, sizeof(c));
    CDQ(1,n+m);
    for(int i=1;i!=m+n+1;++i)
    {
        if(a[i].t==2)
            cout<<ans[i]<<'\n';
    }
}