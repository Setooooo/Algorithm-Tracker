//
// Created by Seto on 2026-02-05
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
// https://www.lanqiao.cn/courses/41070/learning/?id=2817319&compatibility=false
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    string s; cin >> s;
    vector<int>next(s.size());
    for (int i = 1,j=0; i < s.size(); i++) {
        while (j>0&&s[i]!=s[j]) j = next[j-1];
        if (s[i]==s[j]) j++;
        next[i] = j;
    }
    int n =s.size()/(s.size()-next[s.size()-1]);
    int m = s.size()%(s.size()-next[s.size()-1]);
    cout<<((m==0)?n:1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    // ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    // cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}