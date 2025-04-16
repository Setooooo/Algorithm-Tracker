//
// Created by beHe on 25-4-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//字符串你不能相同
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    string str;
    cin>>str;
    ll n=str.size(),total=(n+3)*(n-2)/2;
    ll lef=1,rig=1,cnt1=0,cnt2=0,f=0;
    for(int i=1;i<n;++i){
        if(str[i]==str[i-1]) ++cnt1,++lef;
        else {
            f=1;
            break;
        }
    }
    if(f==1){
        for(int i=n-2;i>=0;--i){
            if(str[i]==str[i+1]) ++cnt2,++rig;
            else{
                break;
            }
        }
        if(str[0]==str[n-1]){
            ll ans=cnt1+cnt2+rig*lef;
            cout<<total-ans<<'\n';
        }else{
            cout<<total-cnt1-cnt2<<'\n';
        }
    }else{
        cout<<0<<'\n';
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