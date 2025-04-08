#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10;
int n,d,k;
vector<int> v[N];
signed main()
{
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++)
    {
        int ts,id;
        cin>>ts>>id;
        v[id].push_back(ts+1);//id在ts时被点赞
    }
    
    for(int i=1;i<=N;i++)
    {
        if(v[i].size()==0) continue;
        
        sort(v[i].begin(),v[i].end());
        
        
        for(int j=0;j+k-1<v[i].size();j++)
        {
            if(v[i][j+k-1]-v[i][j]<d)
            {
                cout<<i<<endl;
                break;
            }
        }
        
      
    }
   
    return 0;
}