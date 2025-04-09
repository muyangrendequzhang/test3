#include <iostream>
using namespace std;
const int N = 1e5;
int a[N];
int b[N];
int vis[N];
int n;
int s = 100;
int getfirst(int num)
{
    int ans=0;
    while (num)
    {
        ans=num % 10;
        num /= 10;
    }
    return ans;
}
void dfs(int step)
{
    
    if (step == n+1)
    {
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
            {
                
                num+=1;
                b[num] = a[i];
            }
            
        }
        
       for (int j = 1; j < num; j++)
        {
          
            if (getfirst(b[j+1]) != b[j] % 10)
            {
                return;
            }
        }
        
        int w = n - num;
        s = min(s, w);
        return;
    }
    vis[step] = 0;
    dfs(step + 1);
    vis[step] = 1;
    dfs(step + 1);

}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << s;
    return 0;
}