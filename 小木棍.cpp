#include<iostream>
using namespace std;
const int N=1e3;
int a[N];
int n;
int ma=0;
int sum=0;
bool check(int m)
{
    if(sum%m==0&&ma<=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        ma=ma>a[i]?ma:a[i];//做出赋值
    }
    int l=0,r=1e2;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l;
    return 0;
}