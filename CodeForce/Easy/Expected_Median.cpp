//
// Created by beHe on 25-3-31.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr ll p=1e9+7;

struct Combine{
    static int N;
    vector<ll>pos,nev;
public:
    Combine():pos(N),nev(N){
        pos[0]=1;
        for(int i=1;i<N;++i) pos[i]=(pos[i-1]*i)%p;
        nev[N-1]=qpow(pos[N-1],p-2);
        for(int i=N-2;i>=0;--i) nev[i]=nev[i+1]*(i+1)%p;
    }
    static ll qpow(ll x,ll mi){
        ll res=1;
        while(mi){
            if(mi&1) res=(res*x)%p;
            mi>>=1,x=x*x%p;
        }
        return res;
    }
    ll combine(ll a,ll b) const{
        if (a < 0 || b < 0 || a < b)
            return 0;
        return pos[a]*nev[a-b]%p*nev[b]%p;
    }
};

int Combine::N=2e5+10;

class Solution{
    static struct Combine com;
    int n,k;
    vector<int> str;
    int count_1,count_0;
    ll ans;
public:
    Solution(int n_,int k_):str(n),n(n_),k(k_),ans(0){
        for(int i=0;i<n;++i) cin>>str[i];
        count_1=count(str.begin(),str.end(),1);
        count_0=str.size()-count_1;
        int m = (k + 1) / 2;
        for (int i = (k-m<=count_0?m:k-count_0); i <= min(k,count_1); ++i) {
            int j = k - i;
            // 正确计算组合数：C(count_1, i) * C(count_0, j)
            ans = (ans + com.combine(count_1, i) * com.combine(count_0, j)) % p;
        }
        cout<<ans<<'\n';
    }
};

Combine Solution::com;

void solve()
{
    int n,m;
    cin>>n>>m;
    Solution two(n,m);
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