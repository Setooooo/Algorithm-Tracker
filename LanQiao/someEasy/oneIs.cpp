#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
  string a1,a2;
  cin>>a1>>a2;
  vector<char> v(a1.begin(),a1.end()),v2(a2.begin(),a2.end());
  sort(v.begin(),v.end());
  sort(v2.begin(),v2.end());
  if (v == v2) {
    cout<<"YES"<<endl;
  }else {
    cout<<"NO"<<endl;
  }
  return 0;
}