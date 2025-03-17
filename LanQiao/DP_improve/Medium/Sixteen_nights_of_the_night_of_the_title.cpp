//
// Created by beHe on 25-3-16.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll N=2e5+10,mod=1e9+7;

ll k,q;
ll dp[N][2][17];
int a[N];
string s;

int count(int sta){
    int res=0;
    while (sta) res+=sta&1,sta>>=1;
    return res;
}

ll dfs(int pos,bool st,bool limit,int sta){

    int cnt=count(sta);
    if(pos<0) return cnt==k;
    if(cnt>k) return 0;
    if(!limit && dp[pos][st][cnt]!=-1) return dp[pos][st][cnt];
    ll res=0;int up=limit?a[pos]:15;
    for(int i=0;i<=up;++i){
        ++q;
        if(!st&&i==0)
            res=(res+dfs(pos-1,st||i>0,limit&&i==up,sta))%mod;
        else
            res=(res+dfs(pos-1,st||i>0,limit&&i==up,sta|1<<i))%mod;
        --q;
    }
    if(!limit) dp[pos][st][cnt]=res;
    return res;
}

ll h(){
    int pos=0;
    for(auto i:s)
        a[pos++]=(i>='0'&&i<='9')?i-'0':i-'A'+10;
    reverse(a,a+pos);
    return dfs(pos-1, false,true,0);
}

void solve()
{
    cin>>s;
    cin>>k;
    cout<<h();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\download\5425.in)");
    cin.rdbuf(file.rdbuf());
    memset(dp,-1,sizeof(dp));
    int T=1;
    while (T--)
    {
        solve();
    }
}