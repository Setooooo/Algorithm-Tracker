//
// Created by beHe on 25-4-3.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

int low(const vector<int>&arr,int x){
    int l=0,r=arr.size()-1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(arr[mid]>=x) r=mid;
        else l=mid+1;
    }
    return arr[l];
}
int up(const vector<int>&arr,int x){
    int l=0,r=arr.size()-1,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(arr[mid]>x) r=mid-1;
        else l=mid;
    }
    return arr[l];
}

void solve()
{
    int n,m;
    cin>>m>>n;
    vector<int>sch(m),stu(n);
    for(auto &i:sch) cin>>i;
    for(auto &i:stu) cin>>i;
    sch.emplace_back(-1e8);
    sch.emplace_back(1e8);
    sort(sch.begin(),sch.end());
    sort(stu.begin(),stu.end());
    ll ans=0;
//    for(const auto &i:stu)
//        ans+=min(abs(i-up(sch,i)),abs(i-low(sch,i)));
    int r=1,l=0;
    for(const auto i:stu){
        while(!(sch[r]>=i&&sch[l]<=i))
        {
            ++l,++r;
        }
        if(sch[r]>=i&&sch[l]<=i){
            ans+=min(abs(sch[r]-i),abs(sch[l]-i));
        }
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
    while (T--)
    {
        solve();
    }
}