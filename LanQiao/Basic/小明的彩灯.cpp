//
// Created by Seto on 2026-03-11
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;

// 我觉得我代码写的还可以喵喵喵

// ？？？这里
void solve() {
    // 处理输入
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    for (int i=0;i<n;++i) cin>>v[i];
    // 处理差分
    for (int i=n-1;i>0;--i) v[i] = v[i]-v[i-1];
    // 彩灯设置
    ll l,r,x;
    while (q--) {
        cin>>l>>r>>x;
        v[l-1]+=x; v[r]-=x;
    }
    // 输出彩灯亮度
    ll now_light = 0;
    for (int i=0;i<n;++i) {
        now_light = v[i]+now_light;
        cout<<(now_light>=0?now_light:0)<<' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T = 1;
    //    cin>>T;
    while (T--) {
        solve();
    }
}
