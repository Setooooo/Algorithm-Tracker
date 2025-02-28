//
// Created by beHe on 25-3-3.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll mod=1000000007;
constexpr ll N=1e7+10;

ll f[N],g[N];

void solve()
{
    ll n;
    cin>>n;
    f[0]=f[1]=1;
    g[0]=0,g[1]=2;
    for(int i=2;i<=n;++i){
        g[i]=((g[i-1]+2*f[i-1])%mod);
        f[i]=((f[i-1]+f[i-2])%mod+g[i-2])%mod;
    }
    cout<<f[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}