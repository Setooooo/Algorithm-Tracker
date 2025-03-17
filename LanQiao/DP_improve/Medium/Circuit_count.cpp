//
// Created by beHe on 25-3-9.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;



inline int gcdreal(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

inline int gcd(int a,int b){
    if(a<b) swap(a,b);
    return gcdreal(a,b);
}

constexpr int N=21;
bool d[N][N];
ll dp[1<<N][N];

void init()
{
    for(int i=0;i<21;++i)
        for(int j=0;j<21;++j)
            if(gcd(i+1,j+1)==1)
                d[i][j]= true;
}

void solve()
{
    init();
    dp[1][0]=1;
    for(int sta=2;sta<(1<<21);++sta){
        for(int i=0;i<21;++i){
            if((sta>>i&1)==0) continue;
            int last_sta=sta-(1<<i);
            for(int j=0;j<21;++j){
                if((last_sta>>j&1)==0||!d[i][j]) continue;
                dp[sta][i]+=dp[last_sta][j];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<21;++i)
        if(d[i][0])
            ans+=dp[(1<<21)-1][i];
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