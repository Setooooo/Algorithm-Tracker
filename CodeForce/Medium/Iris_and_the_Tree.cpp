//
// Created by beHe on 25-3-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n;
    ll w;
    vector<int>fa;
    vector<pair<int,int>>occur;
    vector<int>len;
    vector<int>dep;
public:
    Solution(int n_,ll w_):n(n_),w(w_),
    fa(n+1),occur(n+1,{0,0}),
    len(n+1,0),dep(n+1,0){
        int x,y;
        for(int i=2;i<=n;++i) cin>>fa[i],dep[i]=dep[fa[i]]+1;
        for(int i=1;i<=n;++i) {
            x=i,y=(i==n?1:i+1);
            while(x!=y){
                if(dep[x]<dep[y]) swap(x,y);
                if(!occur[x].first) occur[x].first=i; else occur[x].second=i;
                x=fa[x]; ++len[i];
            }
        }
        ll sum=0,sub=n,p,wei;
        for(int i=1;i<n;++i){
            cin>>p>>wei; sum+=wei;
            if((--len[occur[p].first])==0) --sub;
            if((--len[occur[p].second])==0) --sub;
            cout<<sum*2+sub*(w-sum)<<" \n"[i==n-1];
        }
    };
};


void solve()
{
    ll n,w;
    cin>>n>>w;
    Solution one(n,w);
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