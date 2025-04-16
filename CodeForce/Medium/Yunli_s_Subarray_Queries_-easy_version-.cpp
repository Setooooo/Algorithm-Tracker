//
// Created by beHe on 25-3-23.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//Yunli's Subarray Queries (easy version)
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>arr(n);
    vector<int>ans(n,0);
    for(int i=0;i<n;++i)
        cin>>arr[i],arr[i]-=i;
    map<int,int>cnt;
    multiset<int>res;
    for(int i=0;i<n;++i) res.emplace(0);
    for(int i=0;i<k-1;++i){
        res.erase(res.find(cnt[arr[i]]));
        ++cnt[arr[i]];
        res.emplace(cnt[arr[i]]);
    }
    for(int i=k-1;i<n;++i){
        res.erase(res.find(cnt[arr[i]]));
        ++cnt[arr[i]];
        res.emplace(cnt[arr[i]]);
        ans[i-k+1]=*res.rbegin();
        res.erase(res.find(cnt[arr[i-k+1]]));
        --cnt[arr[i-k+1]];
        res.emplace(cnt[arr[i-k+1]]);
    }
    int x,y;
    for(int i=0;i<q;++i){
        cin>>x>>y;
        cout<<k-ans[x-1]<<'\n';
    }
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