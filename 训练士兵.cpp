#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
struct node
{
    int p;
    int c;
};//c为次数，p为单次的训练费用
const int N=1e5+100;
node a[N];
bool cmp(node n,node m)
{
    return n.c<m.c;
}
int n,s;
signed main()
{
    cin>>n>>s;
    int sum=0;//总训练费用
    for(int i=1;i<=n;i++)
    {
        int p1,c1;
        cin>>p1>>c1;
        a[i].p=p1;
        a[i].c=c1;
        sum+=p1;
    }
    sort(a+1,a+n,cmp);
    int cnt=0;
    int len=1;
   
    while(s<sum)
    {
        for(int i=len;i<=n;i++)
        {
            if(cnt<a[i].c)
            {
                break;
            }
            sum-=a[i].p;
            len++;
        }
        cnt++;
    }
    int sum1=0;
    for(int i=len;i<=n;i++)
    {
        sum1=sum1+(a[i].c-(cnt-1))*a[i].p;
    }
    cout<<sum1+(cnt-1)*s;
    return 0;
}