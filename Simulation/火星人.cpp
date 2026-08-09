#include <bits/stdc++.h>
using namespace std;
int n,m,res=0;
bool a[10005];
int c[10005];
int b[10005];
void dfs(int x){
    if(x>n)
    {
        res++;
        if(res==m+1)
        {
            for(int i=1;i<=n;++i)
            {
                cout<<b[i]<<" ";
            }
            exit(0);
        }
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!res)
        {
            i=c[x];
        }
        if(!a[i])
        {
            a[i]=true;
            b[x]=i;
            dfs(x+1);
            a[i]=false;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i];
    dfs(1);
    return 0;
}