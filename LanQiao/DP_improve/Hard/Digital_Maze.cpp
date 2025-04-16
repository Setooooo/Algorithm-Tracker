//
// Created by beHe on 25-3-17.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//数字迷宫
using namespace std;

using ll=long long;
using ull=unsigned long long;

int n;
int a[6];
ll dp[6][2][2][2][2][2][2][20100];
int poww[7];

ll dfs(int pos,bool limit1,bool limit2,bool limit3,bool ok1,bool ok2,bool ok3,int sum){
    if(pos<0) return (int)(sum==n&&ok1&&ok2&&ok3);
    if(dp[pos][limit1][limit2][limit3][ok1][ok2][ok3][sum]!=-1) return dp[pos][limit1][limit2][limit3][ok1][ok2][ok3][sum];
    int up1=limit1?a[pos]:9;
    int up2=limit2?a[pos]:9;
    int up3=limit3?a[pos]:9;
    ll res=0;
    for(int i=0;i<=up1;++i){
        if(i==2||i==4) continue;
        int du1=ok1?0:i;
        for(int j=du1;j<=up2;++j){
            if(j==2||j==4) continue;
            int du2=ok2?0:j;
            for(int k=du2;k<=up3;++k){
                if(k==2||k==4) continue;
                if(sum+i*poww[pos]+j*poww[pos]+k*poww[pos]>n) break;
                res+=dfs(pos-1,
                         limit1&&i==up1,limit2&&j==up2,limit3&&k==up3,
                              ok1||i<j,ok2||j<k,ok3||i,
                              sum+i*poww[pos]+j*poww[pos]+k*poww[pos]);
            }
        }
    }
    return dp[pos][limit1][limit2][limit3][ok1][ok2][ok3][sum]= res;
}

ll h(int temp){
    int pos=0;
    while (temp) a[pos++]=temp%10,temp/=10;
    return dfs(pos-1,1,1,1,0,0,0,0);
}

void solve()
{
    cin>>n;
    poww[0]=1;
    for(int i=1;i<=6;++i) poww[i]=poww[i-1]*10;
    cout<<h(n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());
    memset(dp,-1,sizeof(dp));
    int T=1;
    while (T--)
    {
        solve();
    }
}