//
// Created by beHe on 25-4-5.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//神秘符文的重复序列
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n,k;
    string &str;
public:
    Solution(int n_,int k_,string &str_):n(n_),k(k_),str(str_){
        ll pre=0,cnt=0,sum=0,cnt1=0;
        for(const auto i:str){
            if(i=='b') sum+=pre,++cnt;
            if(i=='a') ++pre,++cnt1;
        }
        ll ans=sum;
        for(int i=1;i<k;++i){
            ans+=sum+cnt*(cnt1*i);
        }
        cout<<ans;
    };
};


void solve()
{
    int n,m;
    string str;
    cin>>n>>m>>str;
    Solution one(n,m,str);
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