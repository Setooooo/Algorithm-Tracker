//
// Created by beHe on 25-4-5.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//纪律问题
using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr ll p=100003;

ll qpow(ll a,ll b){
    a=a%p;
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%p;
        b>>=1; a=(a*a)%p;
    }
    return res;
}


void solve()
{
    ll n,m;
    cin>>m>>n;
    ll nodis= (qpow(m-1,n-1)*m)%p,isdis= qpow(m,n);
    ll ans=((isdis-nodis)+p)%p;
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}