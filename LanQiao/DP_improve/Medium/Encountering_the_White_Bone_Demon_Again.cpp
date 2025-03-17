//
// Created by beHe on 25-3-9.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll p=998244353;

inline int lowbit(int x){
    return x&-x;
}

inline int getsum(int x){
    int res=0;
    while (x){++res,x-= lowbit(x);}
    return res;
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>dp(m+1,vector<ll>((1<<n)+1,0));
    for(int i=0;i<(1<<n);++i) dp[1][i]=1;
    for(int i=2;i<=m;++i)
        for(int sta=0;sta<(1<<n);++sta){
            if(getsum(sta)<k) continue;
            for(int last_sta=0;last_sta<(1<<n);++last_sta){
                if(getsum(sta&last_sta)>=k) dp[i][sta]=(dp[i][sta]+dp[i-1][last_sta])%p;
            }
        }
    ll ans=0;
    for(int sta=0;sta<(1<<n);++sta)
        ans=(ans+dp[m][sta])%p;
    cout<<ans;
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