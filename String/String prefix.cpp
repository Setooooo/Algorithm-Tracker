//
// Created by Seto on 2026-02-05
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
// https://www.lanqiao.cn/courses/41070/learning/?id=2817318&compatibility=false
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    int n;string s;cin>>n>>s;
    // 求next 数组
    vector<int>next(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j>0&&s[i]!=s[j]) j = next[j - 1];
        if (s[i]==s[j]) ++j;
        next[i] = j;
    }
    //记录数组,最小公共前后缀长
    vector<int>min_s(s.size(),0);
    ull sum = 0;
    //遍历每个前缀串
    for (int i = 0; i < n; i++) {
        if (next[i]==0) {
            continue;
        }
        int prev = next[i];
        min_s[i] = next[i];
        int j=i;
        while (min_s[j]>0){prev = min_s[j],j = min_s[j]-1;}
        min_s[i] = prev;
        sum+=i+1-prev;
    }
    //对于有周期的串来说，最长周期是串长度-其最小公共前缀串长度
    // 原理：如果一个串a是串b的一个周期，那么a至少是b的前缀长度唯一半，
    // b的与a没有对应的后缀也是a和b的前缀，在b为a+a的前缀的情况下，
    // 如果b没有对应的后缀长度越小那么周期越长
    cout<<sum<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);



    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}