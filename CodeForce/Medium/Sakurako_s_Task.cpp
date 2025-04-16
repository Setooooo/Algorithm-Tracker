//
// Created by beHe on 25-3-23.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    ll n,k;
    cin>>n>>k;
    ll g=0;
    vector<ll>arr(n);
    for(auto &i:arr)
        cin>>i,g=__gcd(i,g);
    if(g==0){
        cout<<k<<'\n';
        return;
    }
    ll s=-g;
    if(n!=1){
        for(int i=0;i<n;++i) s+=g,arr[i]=s;
    }
    arr.emplace_back(1e16);
    ll las=0,res=0;
    for(int i=0;i<=n;++i){
        if(k<arr[i]-i){res=arr[i]-(arr[i]-i-k)-1; break;}
    }
    cout<<res<<'\n';
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