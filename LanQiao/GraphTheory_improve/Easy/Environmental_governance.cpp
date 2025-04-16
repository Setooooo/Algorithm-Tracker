//
// Created by beHe on 25-3-27.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//Environmental_governance
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,q;
    vector<vector<ll>>graph,limit,res;
public:
    Solution(int n_,int q_):n(n_),q(q_),
    graph(n+1,vector<ll>(n+1)),
    limit(n+1,vector<ll>(n+1)),
    res(n+1,vector<ll>(n+1)){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j) cin>>graph[i][j];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j) cin>>limit[i][j];
        ll l=0,r=1e7,mid;
        check(1);
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(l==1e7)
            cout<<-1;
        else
            cout<<l;
    }
    ll floyd(){
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    res[i][j]=min(res[i][j],res[i][k]+res[k][j]);
        ll ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j) ans+=res[i][j];
        return ans;
    }
    bool check(int total){

        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j){
                if(i==j) continue;
                else {
                    ll no=graph[i][j]-((total+n-i)/n)-((total+n-j)/n);
                    if(no>limit[i][j]) res[i][j]=res[j][i]=no;
                    else res[i][j]=res[j][i]=limit[i][j];
                }
            }
        return q >= floyd();
    }
};


void solve()
{
    int x,y;
    cin>>x>>y;
    Solution one(x,y);
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