//
// Created by beHe on 25-2-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    ifstream inFile("D://Project//Personal_Projects//GetIt//division.txt");
    if(!inFile.is_open())
        cerr<<" �����޷����ļ�"<<endl;
    else{
        vector<int>numbers;
        int num;
        for(int i=0;i<40;++i)
            if(inFile>>num)
                numbers.emplace_back(num);
            else{

                // �����ȡ���������ļ����ݲ�����ʽ����
                cerr << "�����ļ������ֲ������ڷ��������ݣ�" << endl;
                inFile.close();
                return;
            }
//            cout<<numbers.size()<<'\n';
//        for(const int i:numbers)
//            cout<<i<<' ';
        ll sum= accumulate(numbers.begin(), numbers.end(),0ll);
        ll mid=sum/2+1;
        vector<ll>dp(mid,0);
        for(int i=0;i<40;++i)
        {
            for(ll j=mid;j>=numbers[i];--j){
                dp[j]=max(dp[j],dp[j-numbers[i]]+numbers[i]);
            }
        }
//        cout<<dp[mid-1]<<'\n';
        cout<<dp[mid-1]*(sum-dp[mid-1]);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    while (T--)
    {
        solve();
    }
}