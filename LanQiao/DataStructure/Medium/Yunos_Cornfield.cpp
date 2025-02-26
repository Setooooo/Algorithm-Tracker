//
// Created by 19233 on 2025/2/20.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=2e5+10,M=N/2;

bitset<N>A,B,C;
int cnt[N/2];
struct Query {
    int opt,l,r,x,id;
}query[N/2];

int n,m,arr[N/2],qn;
bool ans[N/2];

void init() {
    qn=sqrt(n);
    sort(query+1,query+1+m,
[](const Query &a,const Query &b) {
    if(a.l/qn!=b.l/qn)
      return a.l<b.l;
    return a.l/qn&1?a.r<b.r:a.r>b.r;
    });
}

void inline add(const int x) {
    if (!cnt[arr[x]])A[arr[x]+M]=true,B[M-arr[x]]=true,C[arr[x]+M]=true;
    ++cnt[arr[x]];
}
void inline del(const int x) {
    if (cnt[arr[x]]==1)A[arr[x]+M]=false,B[M-arr[x]]=false,C[arr[x]+M]=false;
    --cnt[arr[x]];
}

bool check(const int x) {
    switch (x) {
        case 1: {
            if ((A&(B>>x)).any())
                return true;
            break;
        }
        case 2: {
            if ((A&(C>>x)).any())
                return true;
        }
            break;
        case 3: {
            for (ull i=1;i*i<=x;++i)
                if (x%i==0) {
                    if (A[i+M]&&A[x/i+M])
                        return true;
                }
            break;
        }
        case 4: {

            break;
        }
        default:
            break;;
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>arr[i];
    for (int i=1;i<=m;++i)
        cin>>query[i].opt>>query[i].l>>query[i].r>>query[i].x,query[i].id=i;
    init();
    int pl=1,pr=0;
    for (int i=1;i<=m;++i) {
        auto &[opt,l,r,x,id]=query[i];
        while (pl<l) del(pl--);
        while (pl>l) add(++pl);
        while (pr<r) add(++pr);
        while (pr>r) del(pr--);
        if (check(x))
            cout<<"yuno\n";
        else
            cout<<"yumi\n";
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