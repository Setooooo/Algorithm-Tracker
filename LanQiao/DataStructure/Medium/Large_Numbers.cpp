//
// Created by 19233 on 2025/2/21.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=1e5+10;

struct Query {
    int fr,to,idx;
}query[N];

int n,m;
ll p;
string str;

// 快速幂写错了
ll qpow(ll a,ll b) {
    ll res=1;
    while (b) {
        if (b&1)res=(a*res)%p;
        a=(a*a)%p;b>>=1;
    }
    return res;
}

void twoAndFive() {
    vector<ll>sum_a(n+1,0),sum_ja(n+1,0);
    for (int i=1;i<=n;++i) {
        sum_a[i]=sum_a[i-1],sum_ja[i]=sum_ja[i-1];
        if ((str[i-1]-'0')%p==0)
            ++sum_a[i],sum_ja[i]+=i;
    }
    for (int i=1;i<=m;++i) {
        const auto &qu=query[i];
        cout<<sum_ja[qu.to]-sum_ja[qu.fr-1]-(qu.fr-1)*(sum_a[qu.to]-sum_a[qu.fr-1])<<'\n';
    }
}

void otherNuber() {
    int sn=sqrt(n)+1;
    vector<ll>pre(n+1,0),invpow(n+1,1);
    for (int i=1;i<=n;++i) {
        pre[i]=(pre[i-1]*10+str[i-1]-'0')%p;
    }
    ll inv=qpow(10,p-2);
    for (int i=1;i<=n;++i)
        invpow[i]=(invpow[i-1]*inv)%p;
    vector<ll>h(n+1,0);
    for (int i=0;i<=n;++i) {
        h[i]=(pre[i]*invpow[i])%p;
        if (h[i]<0)h[i]+=p;
    }

    vector<ll>lisan=h;
    sort(lisan.begin(),lisan.end());
    lisan.resize(unique(lisan.begin(),lisan.end())-lisan.begin());
    unordered_map<ll,int>hh;
        unsigned int si=lisan.size();
        for (int i=0;i<si;++i) hh[lisan[i]]=i;
    for (int i=0;i<=n;++i) h[i]=hh[h[i]];
    vector<int>cnt(si,0);

    vector<ll>anser(m+1);
    sort(query+1,query+1+m,
        [sn](const Query a,const Query b) {
            if (a.fr/sn!=b.fr/sn) {
                return a.fr<b.fr;
            }
                return ((a.fr/sn)&1)?a.to>b.to:a.to<b.to;
        });
    ll pl=0,pr=-1,ans=0;
    for (int i=1;i<=m;++i) {
        const auto [f,to,idx]=query[i];
        int fr=f-1;
        while (pl<fr) {
            --cnt[h[pl]];
            ans-=cnt[h[pl]];
            ++pl;
        }
        while (pl>fr) {
            --pl;
            ans+=cnt[h[pl]];
            ++cnt[h[pl]];
        }
        while (pr<to) {
            ++pr;
            ans+=cnt[h[pr]];
            ++cnt[h[pr]];
        }
        while (pr>to) {
            --cnt[h[pr]];
            ans-=cnt[h[pr]];
            --pr;
        }
        anser[idx]=ans;
    }
    for (int i=1;i<=m;++i)
        cout<<anser[i]<<'\n';
}

void solve()
{
    cin>>p>>str>>m;
    n=str.size();
    for (int i=1;i<=m;++i) {
        auto &qu=query[i]; cin>>qu.fr>>qu.to,qu.idx=i;
    }
    if (p==2||p==5)
        twoAndFive();
    else
        otherNuber();
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