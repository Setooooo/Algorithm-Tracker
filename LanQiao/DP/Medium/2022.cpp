//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve() {
    vector<vector<ull>> dp(2023, vector<ull>(11, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 2022; ++i)
    {
        for (int j = 10; j > 0; --j) {
            if (i >= j)
                dp[i][j] += dp[i - j][j] + dp[i - j][j - 1];
        }
        if(i<5)
        for(int j=0;j<11;++j)
            cout<<dp[i][j]<<" \n"[j==10];
    }

    cout<<dp[2022][10];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    ifstream file("");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}