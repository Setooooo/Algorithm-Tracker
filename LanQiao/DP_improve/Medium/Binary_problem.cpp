//
// Created by beHe on 25-3-16.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

ll dp[65][2][52];
int a[65],k;


ll dfs(int pos,bool st,bool limit,int cnt){
    if(pos<0) return (int)(cnt==k);

    if(!limit&&dp[pos][st][cnt]!=-1) return dp[pos][st][cnt];

    ll res=0;int up=limit?a[pos]:1;
    for(int i=0;i<=up;++i)
        res+=dfs(pos-1,st||i>0,limit&&(i==up),cnt+i);

    if(!limit) dp[pos][st][cnt]=res;

    return res;
}

ll h(ll n){
    int pos=0;
    while (n) a[pos++]=(n&1ll),n>>=1;
    return dfs(pos-1,false,true,0);
}

void solve()
{
    ll x;
    cin>>x>>k;
    cout<<h(x)<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    memset(dp,-1,sizeof(dp));
    int T=1;
    while (T--)
    {
        solve();
    }
}