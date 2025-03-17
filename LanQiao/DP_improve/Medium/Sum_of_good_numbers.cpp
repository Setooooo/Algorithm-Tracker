//
// Created by beHe on 25-3-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr ll N=15;

pair<ll,ll> dp[12][10][10][10][10][2];
int a[12];
ll poww[12];

pair<ll,ll> dfs(int pos,int last1,int last2,int last3,int now,bool sta,bool limit)
{
    if(pos<0) return sta? make_pair(1ll,0ll):make_pair(0ll,0ll);

    if(!limit&&dp[pos][last1][last2][last3][now][sta].second!=0)
        return dp[pos][last1][last2][last3][now][sta];

    pair<ll,ll>res,ans={0,0}; bool is; int up = limit?a[pos]:9;
    for(int i=0;i<=up;++i){
        is= limit && (i == up);
        if(last2==2&&last3==0&&now==2&&i==2)
            res=dfs(pos-1,last2,last3,now,i,true,is);
        else
            res=dfs(pos-1,last2,last3,now,i,sta,is);
        ans.first+=res.first;
        ans.second+=res.second+1ll*i*poww[pos]*res.first;
    }
    if(!limit) dp[pos][last1][last2][last3][now][sta] = ans;
    return ans;
}


ll h(ll n)
{
    int pos=0;
    while(n)a[pos++]=n%10,n/=10;
    return dfs(pos-1,0,0,0,0,false,true).second;
}

void solve()
{
    ll x,y;
    cin>>x>>y;
    cout<<h(y)-h(x-1)<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    poww[0]=1;
    for(int i=1;i<=10;++i)
        poww[i]=poww[i-1]*10;

    int T=1;
    while (T--)
    {
        solve();
    }
}