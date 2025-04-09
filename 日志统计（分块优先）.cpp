#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+100;
int n,d,k;
struct o
{
    int ts,id;
}a[N];
bool cmp(o a,o b)
{
    if(a.id!=b.id)
    {
        return a.id<b.id;
    }
    else
    {
        return a.ts<b.ts;
    }
}
bool f(int x,int y)
{
    int r=x;
    for(int i=x;i<=y;i++)
    {
        while(a[r+1].ts-a[i].ts<d&&r<y)
        {
            r++;
        }
        if(r+1-i>=k)
        {
            return true;
        }
    }
    return false;
}

signed main()
{
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].ts>>a[i].id;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int x=i,y=i;
        while(a[y].id==a[x].id)y++;
        y--;
        i=y;
        if(f(x,y))
        {
            cout<<a[i].id<<endl;
        }
    }
    return 0;
}