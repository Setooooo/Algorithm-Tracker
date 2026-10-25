//
// Created by Seto on 2026-03-11
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    int n,m;
    while (cin>>n>>m) {
        vector<int>res(n+1);
        for (int i=0;i<n;++i)
            cin>>res[i];
        for (int i=n-1; i>0; i--) {res[i] = res[i]-res[i-1];}
        int x,y,z;
        while (m--) {
            cin>>x>>y>>z;
            res[x-1]+=z,res[y]-=z;
        }
        int as=0;
        for (int i=0;i<n;++i) {
            cout<<res[i]+as<<' ';
            as+=res[i];
        }
        cout<<'\n';
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}