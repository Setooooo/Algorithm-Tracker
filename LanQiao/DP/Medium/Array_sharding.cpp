//
// Created by beHe on 25-3-4.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll mod=1000000007;

void solve()
{
    int n;
    cin>>n;
    vector<ll>arr(n+1),dp(n+1,0);
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    ll minn,maxx;
    dp[0]=1;
    for(int i=1;i<=n;++i)
    {
        minn=maxx=arr[i];
        for(int j=i;j>0;--j)
        {
            minn=minn>arr[j]?arr[j]:minn;
            maxx=maxx>arr[j]?maxx:arr[j];
            if(maxx-minn==i-j) dp[i]=(dp[i]+dp[j-1])%mod;
        }
    }
    cout<<dp[n];
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