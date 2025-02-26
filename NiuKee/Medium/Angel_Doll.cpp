//
// Created by 19233 on 2025/2/24.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class FenwickTree {
    int siz;
    vector<int>arr;
    static int INF;
public:
    FenwickTree(int n_):arr(n_+1,-INF),siz(n_) {
    };
    void add(int pos,int val) {
        while (pos<siz) {
            arr[pos]=max(val,arr[pos]);
            pos+=pos&(-pos);
        }
    }
    int ask(int pos) {
        int res=-INF;
        while (pos) {
            res=max(res,arr[pos]);
            pos-=pos&-pos;
        }
        return res;
    }
    void re(int pos) {
        while (pos<siz) {
            arr[pos]=-INF;
            pos+=pos&-pos;
        }
    }
};
int FenwickTree::INF=0x3f3f3f3f;
constexpr int N=1e6+10;
int n,m,tot,maxy;
struct Node {
    int x,y,opt;
}node[N],b[N];


int ans[N];

bool cmp(const Node&a,const Node&b) {
    if (a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

void work(int st,int ed,int w,int dx,int dy,FenwickTree &FT) {
    int y,num;
    for (int i=st;i!=ed;i+=w) {
        y=(dy==1)?b[i].y:maxy-b[i].y;
        num=dx*b[i].x+dy*b[i].y;
        if (node[b[i].opt].opt==1) {
            FT.add(y,num);
        }else {
            ans[b[i].opt]=min(ans[b[i].opt],num-FT.ask(y));
        }
    }
    for (int i=st;i!=ed;i+=w)
        if (node[b[i].opt].opt==1)
            FT.re(dy==1?b[i].y:maxy-b[i].y);
}

void cdq(int l,int r,FenwickTree&FT) {
    if (l==r)
        return;
    int mid=(l+r)>>1,p=0;
    cdq(l,mid,FT),cdq(mid+1,r,FT);
    for (int i=l;i<=r;++i)
        if (i<=mid&&node[i].opt==1)
            b[++p]=node[i],b[p].opt=i;
        else if (i>mid&&node[i].opt==2)
            b[++p]=node[i],b[p].opt=i;
    sort(b+1,b+p+1,cmp);
    work(p,0,-1,-1,-1,FT);
    work(p,0,-1,-1,1,FT);
    work(1,p+1,1,1,1,FT);
    work(1,p+1,1,1,-1,FT);
}

void solve() {
    cin>>n>>m;
    for (int i=0;i<n;++i) {
        ++tot;cin>>node[tot].x>>node[tot].y;
        node[tot].opt=1;
    }
    for (int i=0;i<m;++i) {
        ++tot;
        cin>>node[tot].opt>>node[tot].x>>node[tot].y;
    }
    maxy=-1;
    for (int i=1;i<=tot;++i)
        maxy=max(maxy,node[i].y);
    ++maxy;
    memset(ans,0x3f,sizeof(ans));
    FenwickTree ft(maxy+2);
    cdq(1,tot,ft);
    for (int i=1;i<=tot;++i) {
        if (node[i].opt==2)
            cout<<ans[i]<<'\n';
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