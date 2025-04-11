#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int n;
const int N=1e6+10;
void solve()
{
    string s;
    cin>>s;
    int num=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]!='l'&&s[i]!='q'&&s[i]!='b')
        {
            break;
        }
        num++;
    }
    int num1=0;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]!='l'&&s[i]!='q'&&s[i]!='b')
        {
            break;
        }
        num1++;
    }
    for(int i=num1;i<(s.size()-num-num1)/2;i++)
    {
        if(s[i]!=s[s.size()-num-1-i+num1])
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        solve();
    }
    return 0;
}