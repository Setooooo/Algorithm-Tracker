//
// Created by beHe on 25-3-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,x;
    cin>>n;
    auto cmp=[](ll &a,ll&b){return a>b;};
    priority_queue<ll,vector<ll>,decltype(cmp)>pq(cmp);
    for(int i=0;i<n;++i) cin>>x,pq.emplace(x);
    ll ans=0,re1,re2;
    while (pq.size()!=1){
        re1=pq.top(),pq.pop();
        re2=pq.top(),pq.pop();
        ans+=re1+re2;
        pq.emplace(re1+re2);
    }
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}