//
// Created by beHe on 25-3-10.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    string str;
    int k,j=0;
    cin>>str>>k;
    while(k--){
        for(j=0;j<str.size();)
            if(str[j]>str[j+1])
            {
                str.erase(j,1);
                break;
            }
            else
                ++j;
    }
    while (str.size()>1&&str.front()=='0')
        str.erase(0,1);
    cout<<str;
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