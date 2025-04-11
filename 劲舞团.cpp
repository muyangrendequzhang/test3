#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  char a,b;
  int t,tt;//t为当前的时间，tt为上一次的时间
  int res=0;
  int cnt=0;
  bool st=true;
  while(cin>>a>>b>>t)
  {
    
        if(a==b&&(st||abs(t-tt)<=1000))
        {
          tt=t;
          cnt++;
          st=false;
        }
        else
        {
          res=max(res,cnt);
          cnt=0;
          st=true;
        }
    
  }
  cout<<res;
  return 0;
}