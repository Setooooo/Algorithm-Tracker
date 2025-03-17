//
// Created by beHe on 25-3-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

ll dp[10][3];
ll a[15];

void pre(){
    dp[0][0]=1;
    for(int i=1;i<=8;++i){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]*10;
    }
}

ll count(ll n) {
    ll tmp = n, cnt = 0;
    int len = 0; bool flag = 0;
    while(n) a[++len] = n % 10, n /= 10;
    a[len+1] = 0;
    for(int i = len; i >= 1; --i) {
        cnt += a[i] * dp[i-1][2];
        if(flag) {
            cnt += a[i] * dp[i-1][0];
        } else {
            if(a[i] > 4) cnt += dp[i-1][0];
            if(a[i] > 6) cnt += dp[i-1][1];
            if(a[i+1] == 6 && a[i] > 2) cnt += dp[i][1];
        }
        if(a[i] == 4 || (a[i+1] == 6 && a[i] == 2)) flag = true;
    }
    return tmp - cnt;
}


void solve()
{
    pre();
    int x,y;
    while (~scanf("%d%d",&x,&y)){
        if(x==0&&y==0) break;
        cout<<count(y+1)-count(x)<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

//    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}
