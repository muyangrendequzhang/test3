//差分题
#include<iostream>
using namespace std;
const int N=3e5+5;
int a[N];
int l[N];
int r[N];
int s[N];
int sum=0;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        a[l[i]]+=1;
        a[r[i]+1]-=1;//差分
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+a[i];
        if(a[i]==0)sum++;
        s[i]=s[i-1]+(a[i]==1);
    }
    for(int i=1;i<=m;i++)
    {

        cout<<sum+s[r[i]]-s[l[i]-1]<<endl;
    }
    return 0;
}