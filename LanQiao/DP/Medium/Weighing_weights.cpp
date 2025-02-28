//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=1e5+10;


void solve()
{
    bitset<N*2>dp;
    int n,x;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        dp|=(dp>>(x));
        dp|=(dp<<(x));
        dp[x+N]=1;
        dp[N-x]=1;
    }
    int ans=0;
    for(int i=1+N;i<N*2;++i){
        ans+=dp[i];
    }
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    ifstream file("");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}