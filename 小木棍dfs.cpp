#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int N=1e4;
int n;
vector<vector<int>>q(N);
queue<int>qe;
int co[N];
bool bfs(int num)
{
    qe.push(num);//把初始的索引点压入对内
    int re[N];
    memset(re,0,sizeof(re));
    while(!qe.empty())
    {
        int te=qe.front();
        qe.pop();
        re[co[te]]++;
        for(int i=0;i<q[te].size();i++)
        {
            qe.push(q[te][i]);
        }
    }
    int nu=0;
    for(int i=1;i<5e3;i++)
    {
        if(nu==0&&re[i]>0)nu=re[i];
        if(nu>0&&re[i]>0&&nu!=re[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int c,f;
        cin>>c>>f;
        co[i]=c;
        q[f].push_back(i);//i是f的子节点
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(bfs(i))
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}