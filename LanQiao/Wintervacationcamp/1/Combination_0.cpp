//
// Created by beHe on 25-4-7.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//组合0
using namespace std;

using ll=long long;
using ull=unsigned long long;

ll C(ll n,ll m){
    ll cnt2=0,cnt5=0,x,y;
    for(ll i=n,j=1;j<=m;--i,++j){
        x=i,y=j;
        while(x%2==0){++cnt2,x/=2;}
        while(x%5==0){++cnt5,x/=5;}
        while(y%2==0){--cnt2,y/=2;}
        while(y%5==0){--cnt5,y/=5;}
    }
    return min(cnt2,cnt5);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    cout<<C(n,m)<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}