//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//砝码称重

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=1e5+10;
bitset<N*2>a,b;

void solve()
{
    ll n,x;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        a|=a>>x;
        a|=a<<x;
        a[N+x]=1;
        a[N-x]=1;
    }
    ll sum=0;
    for(int i=N+1;i<N*2;++i)
        sum+=a[i];
    cout<<sum;
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