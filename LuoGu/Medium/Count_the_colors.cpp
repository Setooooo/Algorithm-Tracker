//
// Created by 19233 on 2025/2/23.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

const int N=2e5,MAXN=1e6+10;
int cnt[MAXN],arr[N],n,m,ans,anser[N]={-1};
int popt,pque;

struct Query {
    int l,r,t,idx;
}query[N];
struct Option {
    int pos,color,t;
}opt[N];

void inline add(int x) {
    if (!cnt[arr[x]])++ans;
    ++cnt[arr[x]];
}
void inline del(int x) {
    if (cnt[arr[x]]==1)--ans;
    --cnt[arr[x]];
}


void init() {
    int sn=pow(n,1.0/2)+1;
    sort(query+1,query+pque+1,[sn](const Query a,const Query b) {
        if (a.l/sn==b.l/sn) {
            if (a.r/sn==b.r/sn)
                return a.t<b.t;
            return a.r<b.r;
        }
        return a.l<b.l;
    });
}

void solve()
{
    char oop;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>arr[i];
    for (int i=1;i<=m;++i) {
        cin>>oop;
        if (oop=='Q')
            cin>>query[++pque].l>>query[pque].r,query[pque].t=i,query[pque].idx=pque;
        else
            cin>>opt[++popt].pos>>opt[popt].color,opt[popt].t=i;
    }
    opt[popt+1].t=1e9;
    opt[popt+1].pos=opt[popt+1].color=0;
    opt[0].t=opt[0].pos=opt[0].color=0;
    init();
    int pl=1,pr=0,pt=0;
    for (int i=1;i<=pque;++i) {
        const auto[l,r,t,idx]=query[i];
        while (pl<l) {
            del(pl++);
        }
        while (pl>l) {
            add(--pl);
        }
        while (pr<r) {
            add(++pr);
        }
        while (pr>r) {
            del(pr--);
        }
        while (opt[pt+1].t<t) {
            ++pt;
            if (opt[pt].pos>r||opt[pt].pos<l) {
                swap(opt[pt].color,arr[opt[pt].pos]);
            }else {
                del(opt[pt].pos);
                swap(opt[pt].color,arr[opt[pt].pos]);
                add(opt[pt].pos);
            }
        }
        while (opt[pt].t>t) {
            if (opt[pt].pos>r||opt[pt].pos<l) {
                swap(opt[pt].color,arr[opt[pt].pos]);
            }else {
                del(opt[pt].pos);
                swap(opt[pt].color,arr[opt[pt].pos]);
                add(opt[pt].pos);
            }
            --pt;
        }
        anser[query[i].idx]=ans;
    }
    for (int i=1;i<=pque;++i)
        cout<<anser[i]<<'\n';
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