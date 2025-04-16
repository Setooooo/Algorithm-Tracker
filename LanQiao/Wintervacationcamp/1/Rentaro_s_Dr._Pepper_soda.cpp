//
// Created by beHe on 25-4-5.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//伦太郎的胡椒博士汽水
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    int n,k;
    cin>>n>>k;
    deque<int>qmin,qmax;
    vector<int>arr(n);
    for(auto &i:arr) cin>>i;
    int i=0,j=0,ans=0;
    while(i<n){
        while(j<n){
            while(!qmax.empty()&&arr[qmax.back()]<=arr[j]) qmax.pop_back();
            qmax.emplace_back(j);
            while(!qmin.empty()&&arr[qmin.back()]>=arr[j]) qmin.pop_back();
            qmin.emplace_back(j);
            if(arr[qmax.front()]-arr[qmin.front()]>k) break;
            ++j;
        }
        if(qmin.front()==i) qmin.pop_front();
        if(qmax.front()==i) qmax.pop_front();
        ans+=j-i-1;
        ++i;
    }
    cout<<ans;
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