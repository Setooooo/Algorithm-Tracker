//
// Created by beHe on 25-3-10.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=14;
ll ans1[N],ans2[N];
ll a[N];

ll dp[N],mi[N];

void solve2(ll n,ll *ans){
    ll tmp=n;
    int len=0;
    while(n) a[++len]=n%10,n/=10;
    for(int i=len;i>=1;--i){
        for(int j=0;j<10;++j) ans[j]+=dp[i-1]*a[i];
        for(int j=0;j<a[i];++j) ans[j]+=mi[i-1];
        tmp-=mi[i-1]*a[i],ans[a[i]]+=tmp+1;
        ans[0]-=mi[i-1];
    }
}

void solve()
{
    mi[0]=1;
    for(int i=1;i<14;++i){
        dp[i]=dp[i-1]*10+mi[i-1];
        mi[i]=mi[i-1]*10;
    }
    ll l,r;
    cin>>l>>r;
    solve2(l-1,ans1);solve2(r,ans2);
    for(int i=0;i<10;++i) cout<<ans2[i]-ans1[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}