#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
int n;//接龙序列的长度
const int N=1e5+100;
int a[N];
int dp[N][13];//当取前i个数的时候，最后一个数字的末尾为j
int first(int num)
{
    int n1;
    while(num)
    {
        n1=num%10;
        num/=10;
    }
    return n1;
}
int final(int num)
{
    return num%10;
}
void solve()
{
    cin>>n;
    memset(dp,1e7,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<10;i++)
    {
        dp[0][i]=0;//一个值不选的，直接转为0排除
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<10;j++)
        {
            dp[i][j]=dp[i-1][j]+1;//不取，末尾不变，并且取的数字少一
        }
        int f=first(a[i]);
        int l=final(a[i]);
        dp[i][l]=min(dp[i][l],dp[i-1][f]);
    }
    int res=1e7;
    for(int i=0;i<10;i++)
    {
        res=min(res,dp[n][i]);
    }
    cout<<res;
    
}
signed main()
{
    solve();
    return 0;
}