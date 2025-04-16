//
// Created by beHe on 25-4-7.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//大衣好累
using namespace std;

using ll=long long;
using ull=unsigned long long;



void solve()
{
    map<int,int>vis;
    int n,x,ma=-1;
    cin>>n;
    for(int i=0;i<2*n;++i){
        cin>>x,++vis[x],ma=max(ma,vis[x]);
    }
    int zero=(ma-(n*2-ma))/2;
    if(zero<=0) cout<<"YES\n";
    else {
        if((n+1)>=zero*2) cout<<"YES\n";
        else cout<<"NO\n";
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