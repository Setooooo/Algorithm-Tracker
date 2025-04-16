//
// Created by beHe on 25-4-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    vector<pair<bool,bool>>init(32,{0,1});
    int n,q;
    cin>>n>>q;
    char f;int x;
    for(int i=0;i<n;++i){
        cin>>f>>x;
        if(f=='&'){
            for(int j=0;j<32;++j){
                init[j].first&=(x>>j)&1;
                init[j].second&=(x>>j)&1;
            }
        }else if(f=='|'){
            for(int j=0;j<32;++j){
                init[j].first|=(x>>j)&1;
                init[j].second|=(x>>j)&1;
            }
        }else{
            for(int j=0;j<32;++j){
                init[j].first^=(x>>j)&1;
                init[j].second^=(x>>j)&1;
            }
        }
    }
    for(int i=0;i<q;++i){
        n=0;
        cin>>x;
        for(int j=0;j<32;++j){
            n+=((x>>j)&1)?(init[j].second<<j):(init[j].first<<j);
        }
        cout<<n<<'\n';
    }
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